#include "cdatacolumn.hpp"

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

virtual int cDataColumn::getSize()
{
	switch(type) {
	String:
		return m_pData->size<QString>();
	DateTime:
		return m_pData->size<QDateTime>();
	Int:
		return m_pData->size<int>();
	Double:	
		return m_pData->size<double>();
	Image:
		return m_pData->size<QImage>();
	}
}

virtual void cDataColumn::getData(int row, QString& val)
{
	Data<T> *pData = static_cast<Data<QString>* >(this);
	pData->getData(row, val);
}

virtual void cDataColumn::getData(int row, QDateTime& val)
{
	Data<T> *pData = static_cast<Data<QDateTime>* >(this);
	pData->getData(row, val);
}

virtual void cDataColumn::getData(int row, int& val)
{
	Data<T> *pData = static_cast<Data<int>* >(this);
	pData->getData(row, val);
}

virtual void cDataColumn::getData(int row, double& val)
{
	Data<T> *pData = static_cast<Data<double>* >(this);
	pData->getData(row, val);
}

virtual void cDataColumn::getData(int row, QImage& val)
{
	Data<T> *pData = static_cast<Data<QImage>* >(this);
	pData->getData(row, val);
}

template<typename T> 
void cDataColumn::DataBase::push_back(const T& value)
{
	Data<T> *pData = static_cast<Data<T>* >(this);
	pData->push_back(value);
}

template <typename T>
int cDataColumn::DataBase::size()
{
	Data<T> *pData = static_cast<Data<T>* >(this);
	return pData->size();
}

template<typename T>
void cDataColumn::DataBase::reserve(int size)
{
	Data<T> *pData = static_cast<Data<T>* >(this);
	return pData->reserve();
}

template<typename T>
void getData(int row, T& val);
{
	Data<T> *pData = static_cast<Data<T>* >(this);
	return pData->getData(row, val);
}
