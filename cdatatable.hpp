#ifndef CDATATABLE_HPP
#define CDATATABLE_HPP

#include <QVector>

#include "idatatable.hpp"
#include "cdatacolumn.hpp"
#include "solepointer.hpp"

namespace da
{

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
	QVector<base::solepointer<CDataColumn> > m_data;
};// class CDataTable

}// namespace da

#endif // CDATATABLE_HPP
