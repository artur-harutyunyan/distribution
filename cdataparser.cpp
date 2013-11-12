#include "cdataparser.hpp"

#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QVector>

#include <iostream>


const char CCSVParser::cszError_Open_Failure[] = "Could not open file";
const char CCSVParser::cszError_No_Header_Data[] = "No header data in file";

CCSVParser::CCSVParser(const QString& csv)
	// TODO swap commented lines with uncommented
	//: m_data_table(0)
	//, m_file_name(csv)
	: m_file_name(csv)
{}

void addRowToTable(QStringList& r, QVector<QStringList>& t)
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
		throw ParserError(cszError_Open_Failure);
	}
	QTextStream ts(&f);
	QString line = ts.readLine();
	if(0 == line.size()) {
		throw ParserError(cszError_No_Header_Data);
	}
	QStringList header = line.split(',');
	QVector<QStringList> table(header.size());
	//m_data_table = new CDataTable;
	while(!f.atEnd())
	{
		// TODO check \" case
		// TODO Check for errors like row.size() != header.size(); and throw ParserError
		line = ts.readLine();
		QStringList row = line.split(',');
		addRowToTable(row, table);
	}
	for(int i = 0; i < table.size(); ++i) {
		ColType t = getColType(table[i]);
		// TODO Something like this
		// CDataColumn c = new CDataColumn(ColType, table[i], header[i]);
		// m_data_table.addCol(c);
	}

	// TODO For testing... Remove this
	//for(int i = 0; i < table.size(); ++i )
	//{
	//	for(int j = 0; j < 10; ++j) {
	//		std::cout << table[i][j].toStdString() << " ";
	//	}
	//	std::cout << std::endl << std::endl;
	//}
}

ColType CCSVParser::getColType(const QStringList& col)
{
	// TODO Not yet implemented
}

IDataTable* CCSVParser::getDataTable()
{
	//Q_ASSERT(0 == m_data_table);
	//return m_data_table;
	return 0;
}

QStringList CCSVParser::parseLine(const QString& line)
{
	int n = line.size();
	int p = 0;

}

/*
	// TODO For testing... Remove this
int main()
{
	CCSVParser p("../dtf/ParameterData.Pivot.csv");
	p.parse();
	return 0;
}

*/
