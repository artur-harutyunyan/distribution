#ifndef IDATACOLUMN_HPP
#define IDATACOLUMN_HPP

#include <QString>
#include <QDateTime>
#include <QImage>

namespace da
{

class IDataColumn
{
public:
	enum EType { Int = 0,
			Double,
			String,
			DateTime,
			Image,
			TypeCount };

	virtual ~IDataColumn()
	{}

	virtual QString getName() = 0;
	virtual int getSize() = 0;
	virtual EType getType() = 0;
	virtual void getData(int row, QString& value) = 0;
	virtual void getData(int row, QDateTime& value) = 0;
	virtual void getData(int row, int& value) = 0;
	virtual void getData(int row, double& value) = 0;
	virtual void getData(int row, QImage& value) = 0;
};// class IDataColumn

}// namespace da

#endif // IDATACOLUMN_HPP
