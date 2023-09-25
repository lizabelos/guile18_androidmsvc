QT       += core gui widgets

CONFIG += c++11
CONFIG += automoc

# TARGET = GuileInterpreter
# TEMPLATE = lib

SOURCES += main.cpp
HEADERS += MainWindow.h

LIBS += -L../../local/lib -lguile -lgmp

CONFIG(release, debug|release): CONFIG += optimize_full
CONFIG(debug, debug|release): CONFIG += debug_info

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
