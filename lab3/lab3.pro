QT += core gui widgets
TARGET = MorseConverter
TEMPLATE = app

SOURCES += main.cpp \
        mainwindow.cpp \
        morseconverter.cpp \
        morsecodetable.cpp

HEADERS += mainwindow.h \
        morseconverter.h \
        morsecodetable.h

FORMS += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++17
