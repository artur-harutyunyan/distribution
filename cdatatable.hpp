#ifndef CDATATABLE
#define  CDATATABLE

#include <QVector>

#include "idatatable.hpp"
#include "idatacolumn.hpp"

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

	void append(IDataColumn* col)
	{
		m_data.append(col);
	}

	virtual ~CDataTable()
	{
		int size = m_data.size();
		for (int i = 0; i < size; ++i)
		{
			if (m_data[i])
				delete m_data[i];
		}
	}

private:
	// vector of idatacolumns'
	QVector<IDataColumn*> m_data;
};// class CDataTable

}// namespace da

#endif // CDATATABLE
