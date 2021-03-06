################################################################################
#                                                                              #
#  DISTRIBUTION MODULE QT MAKE FILE                                            #
#                                                                              #
################################################################################

TEMPLATE = app
TARGET   = distribution
DEFINES += DISTRIBUTION_LIB



#Check if destination directory is specified
isEmpty(BUILD_OUTPUT){
	BUILD_OUTPUT = build
	warning("BUILD_OUTPUT is not specified! Set it to \"build\"/")
}

#Default configuration
CONFIG += qt; 

DESTDIR = $$BUILD_OUTPUT/bin
DLLDESTDIR = $$BUILD_OUTPUT/lib
OBJECTS_DIR = $$BUILD_OUTPUT/temp
MOC_DIR = $$BUILD_OUTPUT/temp/moc_generated
UI_DIR  = $$BUILD_OUTPUT/temp/uic_generated
RCC_DIR = $$BUILD_OUTPUT/temp/rcc_generated

CONFIG(debug, debug|release) {
	message(Generating $$TARGET Makefile for $(QMAKESPEC) (Debug mode).)
	DEFINES += _DEBUG
} else {
    message(Generating $$TARGET Makefile for $(QMAKESPEC) (Release mode))
}

#Compiler Options
unix:QMAKE_CXXFLAGS_RELEASE += -fno-strict-aliasing

#Header file(s)
HEADERS	+=		./solepointer.hpp \
			./canalyzer.hpp \			
			./capplication.hpp \
			./cchartgallery.hpp \
			./cdatacolumn.hpp \
			./cdataparser.hpp \
			./cdatatable.hpp \
			./cdistribution.hpp \
			./cfunctions.hpp \
			./cgalleryview.hpp \
			./cmaingallery.hpp \
			./cmaintable.hpp \
			./cmainview.hpp \
			./cmainwindow.hpp \
			./cmodule.hpp \
			./csimpleanalyzer.hpp \
			./ctableview.hpp \
			./idatacolumn.hpp \
			./idatatable.hpp

#Source file(s)
SOURCES	+=	./cdatacolumn.cpp \
			./cdataparser.cpp \
			./cdatatable.cpp \
			./main.cpp


#end of file#
