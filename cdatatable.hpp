#ifndef CDATATABLE_HPP
#define CDATATABLE_HPP

#include <QVector>

#include "idatatable.hpp"

namespace da
{

class CDataColumn;

class CDataTable : public IDataTable
{
public:
	virtual IDataColumn* getColumn(int index);
	virtual int getColumnCount();
	virtual QString getColumnName(int index);
	virtual int getRowCount();
	virtual QStringList getColumnNames();

	virtual ~CDataTable();

private:
	// vector of cdatacolumns'
	QVector<CDataColumn* > m_data;
};// class CDataTable

}// namespace da

#endif // CDATATABLE_HPP
