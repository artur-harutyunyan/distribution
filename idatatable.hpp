#ifndef IDATATABLE_H
#define IDATATABLE_H

#include <QGlobal>

#include "iDataColumn.h"

namespace da
{

class IDataTable
{
public:
	virtual IDataColumn* getColumn() = 0;
	virtual int getColumnCount() = 0;
	virtual QString getColumnName() = 0;
	virtual int getRowCount() = 0;
	QStringList getColumnNames();
}; // class DataColumn

}// namespace da

#endif // IDATATABLE_H
