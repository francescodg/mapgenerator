TEMPLATE = app

SOURCES += src/*  # Source directory
HEADERS += include/* # Header files
FORMS += ui/mainwindow.ui

INCLUDEPATH += include/ # 
DEPENDPATH += include/ # List of all directories to look in to resolve dependencies

MOC_DIR = moc/ # Store Meta Object Compiler objects
OBJECTS_DIR = objects/ # Store objects generated after compilation
UI_DIR = include/ui/ # Store ui_ generated files

QMAKE_CXXFLAGS += -g -std=c++0x # Use C++11
CONFIG += qt warn_on release # 
TARGET = a.out
