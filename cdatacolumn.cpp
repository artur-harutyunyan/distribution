#include "cdatacolumn.hpp"

namespace da
{

CDataColumn::CDataColumn(EType type)
	: m_name(""),
	m_type(type)
{
	switch(m_type) {
	String:
		m_pData = new Data<QString>;
	DateTime:
		m_pData = new Data<QDateTime>;
	Int:
		m_pData = new Data<int>;
	Double:	
		m_pData = new Data<double>;
	Image:
		m_pData = new Data<QImage>;
	}
}
CDataColumn::CDataColumn(const QString& name, EType type)
	: m_name(name),
	m_type(type)
{
	switch(m_type) {
	String:
		m_pData = new Data<QString>;
	DateTime:
		m_pData = new Data<QDateTime>;
	Int:
		m_pData = new Data<int>;
	Double:	
		m_pData = new Data<double>;
	Image:
		m_pData = new Data<QImage>;
	}
}

int CDataColumn::getSize()
{
	switch(m_type) {
	String:
		return m_pData->getSize<QString>();
	DateTime:
		return m_pData->getSize<QDateTime>();
	Int:
		return m_pData->getSize<int>();
	Double:	
		return m_pData->getSize<double>();
	Image:
		return m_pData->getSize<QImage>();
	}
}

void CDataColumn::getData(int row, QString& val)
{
	Data<QString> *pData = static_cast<Data<QString>* >(m_pData);
	pData->getData(row, val);
}

void CDataColumn::getData(int row, QDateTime& val)
{
	Data<QDateTime> *pData = static_cast<Data<QDateTime>* >(m_pData);
	pData->getData(row, val);
}

void CDataColumn::getData(int row, int& val)
{
	Data<int> *pData = static_cast<Data<int>* >(m_pData);
	pData->getData(row, val);
}

void CDataColumn::getData(int row, double& val)
{
	Data<double> *pData = static_cast<Data<double>* >(m_pData);
	pData->getData(row, val);
}

void CDataColumn::getData(int row, QImage& val)
{
	Data<QImage> *pData = static_cast<Data<QImage>* >(m_pData);
	pData->getData(row, val);
}

template<typename T> 
void CDataColumn::DataBase::push_back(const T& value)
{
	Data<T> *pData = static_cast<Data<T>* >(this);
	pData->push_back(value);
}

template <typename T>
int CDataColumn::DataBase::getSize()
{
	Data<T> *pData = static_cast<Data<T>* >(this);
	return pData->size();
}

template<typename T>
void CDataColumn::DataBase::reserve(int size)
{
	Data<T> *pData = static_cast<Data<T>* >(this);
	return pData->reserve();
}

template<typename T>
void CDataColumn::DataBase::getData(int row, T& val)
{
	Data<T> *pData = static_cast<Data<T>* >(this);
	return pData->getData(row, val);
}

} // namespace da
