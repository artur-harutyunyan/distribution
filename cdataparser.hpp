#ifndef CDATAPARSER_HPP
#define CDATAPARSER_HPP

#include "cdatatable.hpp"
#include "idatacolumn.hpp"

#include <QString>
#include <QVector>
#include <QStringList>


#include <exception>
#include <string>

namespace da {
namespace io {

class ParserError : public std::exception
{
	std::string m_message;
	int m_row;
	public:
		ParserError(const std::string& s, int r)
			: m_message(s)
			, m_row(r)
		{}
		const char* what()
		{
			return m_message.c_str();
		}
		const char* format()
		{
			return QString("Parse error at line %1: %2").arg(m_row).arg(m_message.c_str()).toAscii().data();
		}
		~ParserError() throw()
		{}
};


class CCSVParser
{
public:
	/** 
	 * @brief CCSVParser constructor.
	 * @param[in] csv CSV file name.
	 */
	CCSVParser(const QString& csv);

	/**
	 * @brief CCSVParser destructor.
	 */
	~CCSVParser();

	/**
	 * @brief parse the specified CSV file.
	 */
	void parse();

	/**
	 * @brief get the parsed CSV file as IDataTable.
	 * @return the constructed IDataTable.
	 */
	IDataTable* takeDataTable();

private:
	typedef QVector<QStringList> Table;
	void addRowToTable(QStringList& sl, Table& tbl);
	QStringList parseLine(const QString& line);
	EType getColType(const QStringList& col); // Where is EType?
	bool canCast(const QString& s, EType t);
	CDataTable* m_data_table;
	const QString m_file_name;

	static const char cszError_Open_Failure[];
	static const char cszError_No_Header_Data[];
	static const char cszError_Incorrect_Row[];
};

} // namespace io
} // namespace da
#endif // CDATAPARSER_HPP
