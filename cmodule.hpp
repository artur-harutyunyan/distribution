#ifndef CMODULE_HPP
#define CMODULE_HPP

#include <QObject>
#include <QString>

namespace da
{

class CMainWindow;

//
/// This is base class for module concept.
//
class CModule : public QObject
{
	Q_OBJECT
public:
	void setMainWindow(CMainWindow *mw)
	{
		m_pMainWindow = mw;
		initConnections();
	}

	void initConnections()
	{
		connect(m_pMainWindow, SIGNAL(openFile(const QString&)),
				this, SLOT(onOpenFile(const QString&)));
	}
private slots:
	virtual void onOpenFile(const QString& filename)
	{
	// Empty function
	}
private:
	// main window memeber
	// We use aggregation relation
	CMainWindow *m_pMainWindow;
}

} // namespace da

#endif // CMODULE_HPP
