#ifndef CDISTRIBUTIONMODULE_H
#define CDISTRIBUTIONMODULE_H

#include <QObject>

#include <cmodule.hpp>
#include "CAnalysisTableModel.h"

namespace da
{

class CDistributionModule : public QObject
{
	Q_OBJECT
public:

private:
	IDataTable* table;

	CAnalysisTableModel* tableModel;
};//class CDistributionModule

}// namespace da

#endif //CDISTRIBUTIONMODULE_H
