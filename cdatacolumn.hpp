#ifndef CDATACOLUMN_HPP
#define CDATACOLUMN_HPP

#include "idatacolumn.hpp"

#include <QImage>
#include <QVector>
#include <QString>

namespace da
{

class CDataColumn : public IDataColumn
{

	// constructor/destructor
public:
	CDataColumn()
		:m_name(""),
		m_pData(0)
	{}

	//
	/// Create new column of specified type.
	/// Name will be empty.
	//
	CDataColumn(EType type);

	//
	/// Create new column of speciified type and name.
	//
	CDataColumn(const QString& name, EType type);
	//
	/// Create new column of specified type from input iterators.
	//
	template<typename InputIter>
	CDataColumn(EType, const InputIter&, const InputIter&);

	virtual ~CDataColumn()
	{}
	// functions
public:
	virtual int getSize();

	virtual EType getType();

	virtual QString getName();

	void setName(QString& newName)
	{
		m_name = newName;
	}

	virtual void getData(int row, QString& val);
	virtual void getData(int row, QDateTime& val);
	virtual void getData(int row, int& val);
	virtual void getData(int row, double& val);
	virtual void getData(int row, QImage& val);

	template <typename T>
	void  push_back(const T& val);

	//
	/// append new elements from first to last
	/// TODO check internal and element's types
	//
	template<typename InputIter>
	void fill(const InputIter& first, const InputIter& last);

private:

	class DataBase
	{
	public:
		template<typename T> 
		void push_back(const T& value);

		template <typename T>
		int getSize();

		template<typename T>
		void reserve(int size);

		template<typename T>
		void getData(int row, T& val);
	};

	template<typename T>
	class Data : public DataBase, public QVector<T>
	{
	public:
		void getData(int row, T& val)
		{
			val = QVector<T>::at(row);
		}
	};

	// members
private:
	//
	/// Name of column
	//
	QString m_name;
	//
	/// Type of column
	//
	EType m_type;
	//
	/// Ppointer to the actual data
	//
	DataBase *m_pData;
};// class CDataColumn

}// namespace da

#endif // CDATACOLUMN_HPP
