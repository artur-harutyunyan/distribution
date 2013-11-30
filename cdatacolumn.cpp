#include "cdatacolumn.hpp"

#include <iterator> // std::distance()

namespace da
{

CDataColumn::CDataColumn(EType type)
	: m_name(""),
	m_type(type)
{
	switch(m_type) {
	case String:
		m_pData = new Data<QString>;
		break;
	case DateTime:
		m_pData = new Data<QDateTime>;
		break;
	case Int:
		m_pData = new Data<int>;
		break;
	case Double:	
		m_pData = new Data<double>;
		break;
	case Image:
		m_pData = new Data<QImage>;
		break;
	default:
		Q_ASSERT(false);
		break;
	}
}

template<typename InputIter>
CDataColumn::CDataColumn(EType type, const InputIter& first, const InputIter& last)
	: m_name(""),
	m_type(type)
{
	switch(m_type) {
	case String:
		m_pData = new Data<QString>;
		fill(first, last);
		break;
	case DateTime:
		m_pData = new Data<QDateTime>;
		fill(first, last);
		break;
	case Int:
		m_pData = new Data<int>;
		fill(first, last);
		break;
	case Double:	
		m_pData = new Data<double>;
		fill(first, last);
		break;
	case Image:
		m_pData = new Data<QImage>;
		fill(first, last);
		break;
	default:
		Q_ASSERT(false);
		break;
	}
}

CDataColumn::CDataColumn(const QString& name, EType type)
	: m_name(name),
	m_type(type)
{
	switch(m_type) {
	case String:
		m_pData = new Data<QString>;
		break;
	case DateTime:
		m_pData = new Data<QDateTime>;
		break;
	case Int:
		m_pData = new Data<int>;
		break;
	case Double:	
		m_pData = new Data<double>;
		break;
	case Image:
		m_pData = new Data<QImage>;
		break;
	default:
		Q_ASSERT(false);
		break;
	}
}

int CDataColumn::getSize()
{
	switch(m_type) {
	case String:
		return m_pData->getSize<QString>();
		break;
	case DateTime:
		return m_pData->getSize<QDateTime>();
		break;
	case Int:
		return m_pData->getSize<int>();
		break;
	case Double:	
		return m_pData->getSize<double>();
		break;
	case Image:
		return m_pData->getSize<QImage>();
		break;
	default:
		Q_ASSERT(false);
		return 0;
		break;
	}
}

EType CDataColumn::getType()
{
	return m_type;
}

QString CDataColumn::getName()
{
	return m_name;
}

template<typename InputIter>
void CDataColumn::fill(const InputIter& first, const InputIter& last)
{
	int size = std::distance(first, last);
	switch(m_type) {
	case String:
		//Data<QString>* pData = static_cast<Data<QString>* >(m_pData);
		m_pData->reserve<QString>(size);
		break;
	case DateTime:
		//Data<QDateTime>* pData = static_cast<Data<QDateTime>* >(m_pData);
		m_pData->reserve<QDateTime>(size);
		break;
	case Int:
		//Data<int>* pData = static_cast<Data<int>* >(m_pData);
		m_pData->reserve<int>(size);
		break;
	case Double:	
		//Data<double>* pData = static_cast<Data<double>* >(m_pData);
		m_pData->reserve<double>(size);
		break;
	case Image:
		//Data<QImage>* pData = static_cast<Data<QImage>* >(m_pData);
		m_pData->reserve<QImage>(size);
		break;
	default:
		Q_ASSERT(false);
		return 0;
		break;
	}
	//m_pData->reserve(size);
	for(; first != last; ++first)
	{
		m_pData->push_back(*first);
	}
}
template <typename T>
void  CDataColumn::push_back(const T& val)
{
	m_pData->push_back(val);
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
