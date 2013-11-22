#include "CApplication.hpp"
#include "CMainWindow.hpp"

int main(int argc, char* argv[])
{
	CApplication obApp(argc, argv);
	CMainWindow wWin(obApp.getModule());

	wWin.show();


	return obApp.exec();
}
