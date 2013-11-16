#include "cdataparser.hpp"
#include "cdatacolumn.hpp"

#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDateTime>

#include <iostream>

namespace da {
namespace io {


const char CCSVParser::cszError_Open_Failure[] = "Could not open file";
const char CCSVParser::cszError_No_Header_Data[] = "No header data in file";
const char CCSVParser::cszError_Incorrect_Row[] = "Incorrect row size";

CCSVParser::CCSVParser(const QString& csv)
	: m_data_table(0)
	, m_file_name(csv)
{}

CCSVParser::~CCSVParser()
{
	if(0 != m_data_table) {
		delete m_data_table;
	}
}

void CCSVParser::addRowToTable(QStringList& r, QVector<QStringList>& t)
{
	int n = t.size();
	Q_ASSERT(n == r.size());
	for(int i = 0; i < n; ++i) {
		t[i].push_back(r[i]);
	}
}

void CCSVParser::parse()
{
	QFile f(m_file_name);
	if(!f.open(QIODevice::ReadOnly)) {
		throw ParserError(cszError_Open_Failure, 0);
	}
	QTextStream ts(&f);
	QString line = ts.readLine();
	if(0 == line.size()) {
		throw ParserError(cszError_No_Header_Data, 0);
	}
	QStringList header = line.split(',');
	Table table(header.size());
	//m_data_table = new CDataTable;
	int row_num = 1;
	while(!f.atEnd())
	{
		line = ts.readLine();
		QStringList row = parseLine(line);
		if(row.size() != header.size()) {
			throw ParserError(cszError_Incorrect_Row, row_num);
		}
		addRowToTable(row, table);
		++row_num;
	}
	for(int i = 0; i < table.size(); ++i) {
		EType t = getColType(table[i]);
		CDataColumn* c = new CDataColumn(header[i], t);
		// for(...)
		// 	c.push_back(table[i][j]);
		// m_data_table.addCol(c);
	}
}

EType CCSVParser::getColType(const QStringList& col)
{
	int type = Int;
	QStringList::ConstIterator it = col.begin();
	for(; it != col.end(); ++it) {
		if(!canCast(*it, static_cast<EType>(type))) {
			++type;
		}
		if(String == type) {
			break;
		}
	}
	if(String == type) {
		it = col.begin();
		type = DateTime;
		for(; it != col.end(); ++it) {
			if(!canCast(*it, static_cast<EType>(type))) {
				type = String;
				break;
			}
		}
	}
	return static_cast<EType>(type);
}

bool CCSVParser::canCast(const QString& s, EType t)
{
	bool ok;
	switch(t) {
		case Int: {
			s.toInt(&ok);
			break;
		}
		case Double: {
			s.toDouble(&ok);
			break;
		}
		case DateTime: {
			QDateTime dt = QDateTime::fromString(s, "Some format");
			ok = dt.isValid();
			break;
		}
		case String: {
			ok = true;
			break;
		}
		default: {
			ok = false;
			break;
		}
	}
	return ok;
}

IDataTable* CCSVParser::takeDataTable()
{
	Q_ASSERT(0 != m_data_table);
	IDataTable* dt = m_data_table;
	m_data_table = 0;
	return dt;
}

QStringList CCSVParser::parseLine(const QString& line)
{
	// don't sure if this works :(
	int n = line.size();
	QStringList sl;
	QString s = "";
	for(int i = 0; i < n-1; ++i) {
		if('\\' == line[i]) {
			if(',' == line[i+1]) {
				s.append(',');
				++i;
			} else if('\\' == line[i+1]) {
				++i;
				s.append('\\');
			} else {
				s.append('\\');
			}
		} else if(',' == line[i]) {
			sl.push_back(s);
			s = "";
		} else {
			s.append(line[i]);
		}
	}
	s.append(line[n-1]);
	sl.push_back(s);
	return sl;
}

} // namespace io
} // namespace da
