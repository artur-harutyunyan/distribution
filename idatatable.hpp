#ifndef IDATATABLE_H
#define IDATATABLE_H

#include "idatacolumn.hpp"

#include <QStringList>

namespace da
{

class IDataTable
{
public:
	virtual IDataColumn* getColumn(int index) = 0;
	virtual int getColumnCount() = 0;
	virtual QString getColumnName(int index) = 0;
	virtual int getRowCount() = 0;
	virtual QStringList getColumnNames()
	{
		QStringList ret;
		int count = getColumnCount();
		for (int i = 0; i < count; ++i)
		{
			ret << getColumnName(i);
		}
		return ret;
	}

	virtual ~IDataTable()
	{};
}; // class DataColumn

}// namespace da

#endif // IDATATABLE_H
