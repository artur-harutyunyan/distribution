#ifndef CDATATABLE
#define  CDATATABLE

#include "idatacolumn.hpp"
#include <QImage>
#include <QVector>
#include <QVariant>
#include <QString>

namespace da
{

class CDataColumn : public IDataColumn
{
	class DataBase
	{
	public:
		template<typename T> 
		void push_back(const T& value)
		{
			Data<T> *pData = static_cast<Data<T>* >(this);
			pData->push_back(value);
		}

		template <typename T>
		int size()
		{
			Data<T> *pData = static_cast<Data<T>* >(this);
			return pData->size();
		}
	};

	template<typename T>
	class Data : public DataBase
	{
		QVector<T> values;
	public:
		void push_back(const T& val)
		{
			values.push_back(val);
		}

		int size()
		{
			return values.size();
		}

		void reserve(int size)
		{
			values.reserve(size);
		}
	};
	// members
private:
	//
	/// Type of column
	//
	EType type;
	//
	/// Name of column
	//
	QString name;

	//
	/// Pointer to the actual data
	//
	DataBase *pData;

	// constructor/destructor
public:
	CDataColumn()
		:name(""),
		pData(0)
	{}

	virtual ~CDataColumn()
	{}
	// function
public:
	virtual int getSize()
	{
		switch(type) {
		String:
			return pData->size<QString>();
		DateTime:
			return pData->size<QDateTime>();
		Int:
			return pData->size<int>();
		Double:	
			return pData->size<double>();
		Image:
			return pData->size<QImage>();
		}
	}

	virtual EType getType()
	{
		return type;
	}

	virtual QString getName()
	{
		return name;
	}

	void setName(QString& newName)
	{
		name = newName;
	}

};// class CDataColumn

}// namespace da

#endif // CDATATABLE
