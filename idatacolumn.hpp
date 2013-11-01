#ifndef IDATACOLUMN_H
#define IDATACOLUMN_H

#include <QtGlobal.h>
#include <QStringList>
#include <QDateTime>

namespace da
{

class IDataColumn
{
public:
	static enum EType {	String = 0 ,
						DateTime,
						Int,
						Double,
						Image,
						TypeCount};
public:

	virtual ~IDataColumn();
	virtual QString getName() = 0;
	virtual int getSize() = 0;
	virtual Type getType() = 0;
	virtual void getData(int row, int& value) = 0;
	virtual void getData(int row, double& value) = 0;
	virtual void getData(int row, QDateTime& value) = 0;
};// class IDataColumn

}// namespace da

#endif // IDATACOLUMN_H
