#ifndef CAPPLICATION_HPP
#define CAPPLICATION_HPP

#include <QApplication>

class CApplication : public QApplication
{
public:
	CApplication( int argc, char** argv) : QApplication( argc, argv )
	{}

	getModule()
	{
		return //something;
	}

}

#endif //CAPPLICATION_HPP