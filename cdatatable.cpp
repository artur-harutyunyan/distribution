#include "cdatatable.hpp"

namespace da
{

IDataColumn* CDataTable::getColumn(int index)
{
	return m_data.at(index);
}

int CDataTable::getColumnCount()
{
	return m_data.size();
}

QString CDataTable::getColumnName(int index)
{
	return m_data.at(index)->getName();
}

int CDataTable::getRowCount()
{
	return m_data.at(0)->getSize();
}

QStringList CDataTable::getColumnNames()
{
	return QStringList(); // fix this
}

} // namespace da
