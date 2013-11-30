#ifndef CDATATABLE_HPP
#define CDATATABLE_HPP

#include <QVector>

#include "idatatable.hpp"
#include "cdatacolumn.hpp"
#include "soleptr.hpp"

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
	void addDataColumn(CDataColumn *);

	virtual ~CDataTable();

private:
	// vector of cdatacolumns'
	QVector<base::SolePtr<CDataColumn> > m_data;
};// class CDataTable

}// namespace da

#endif // CDATATABLE_HPP
