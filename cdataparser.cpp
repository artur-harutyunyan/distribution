#include "cdataparser.h"

#include <QStringList>
#include <QFile>
#include <QTextStream>


const char* CCSVParser::cszError_Open_Failure[] = "Could not open file";
const char* CCSVParser::cszError_No_Header_Data[] = "No header data in file";

CCSVParser::CCSVParser(const QString& csv)
	: m_data_table(0)
	, m_file_name(csv)
{}

void CCSVParser::parse()
{
	QFile f(m_file_name);
	if(!f.open(QIODevice::ReadOnly)) {
		throw runtime_error(cszError_Open_Failure);
	}
	QTextStream ts(f);
	QString line = ts.readLine();
	if(0 == line.size()) {
		throw runtime_error(cszError_No_Header_Data);
	}
	QStringList header = line.split(',');
	m_data_table = new CDataTable;
	while(!f.eof())
	{
		line = ts.readLine();
		QStringList
	}

}

IDataTable* CCSVParser::getDataTable()
{
	Q_ASSERT(0 == m_data_table);
	return m_data_table;
}
