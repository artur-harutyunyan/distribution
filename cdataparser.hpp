#ifndef CDATAPARSER_HPP
#define CDATAPARSER_HPP

#include "cdatatable.hpp"

#include <QString>


#include <exception>
#include <string>

class ParserError : public std::exception
{
	// TODO add format
	std::string m_message;
	public:
		ParserError(const std::string& s)
			: m_message(s)
		{}
		const char* what()
		{
			return m_message.c_str();
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
	 * @brief parse the specified CSV file.
	 */
	void parse();

	/**
	 * @brief get the parsed CSV file as IDataTable.
	 * @return the constructed IDataTable.
	 */
	IDataTable* getDataTable();
private:

	QStringList parseLine(const QString& line);
	ColType getColType(cosnt QStringList& col);
	//CDataTable* m_data_table;
	const QString m_file_name;

	static const char cszError_Open_Failure[];
	static const char cszError_No_Header_Data[];
};

#endif // CDATAPARSER_HPP
