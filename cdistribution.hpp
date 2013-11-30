#ifndef CDISTRIBUTIONMODULE_HPP
#define CDISTRIBUTIONMODULE_HPP

#include <QObject>

#include "cmodule.hpp"
#include "idatatable.hpp"
#include "cdataparser.hpp"
#include "canalyzer.hpp"
//#include "CAnalysisTableModel.h"

namespace da
{

class CDistributionModule : public CModule
{
	Q_OBJECT
public:
private slots:
	//
	/// This function opens file using parser,
	/// takes data table from it and gaves to analyzer
	virtual void onOpenFile(const QString& filename)
	{
		CCSVParser* parser = new CCSVParser(filename);
		parser->parse();
		IDataTable* table = parser->takeDataTable();
		// TODO planning to be function like this
		//m_pAnalyzer->setDataTable(table);
	}
private:
	//IDataTable* m_pTable;
	//CCSVParser* m_pParser;
	CAnalyzer* m_pAnalyzer;
	CStatistics* m_pStat;

	//CAnalysisTableModel* tableModel;
};//class CDistributionModule

}// namespace da

#endif //CDISTRIBUTIONMODULE_HPPPP
