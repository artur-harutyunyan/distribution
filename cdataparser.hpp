#ifndef CDATAPARSER_HPP
#define CDATAPARSER_HPP

#include "cdatatable.hpp"

#include <QString>

#include <exception>


class CCSVParser
{
	static const char* cszError_Open_Failure[];
	static const char* cszError_No_Header_Data[];
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
	CDataTable* m_data_table;
	const QString m_file_name;
};

#endif // CDATAPARSER_HPP
