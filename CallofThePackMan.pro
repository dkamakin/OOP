QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
INCLUDEPATH += $$PWD/inc

SOURCES += \
    src/view/levelmapper.cpp \
    src/view/objectmapper.cpp \
    src/gameobjects/attacktemplate.cpp \
    src/gameobjects/debufftemplate.cpp \
    src/logger/logger.cpp \
    src/logger/consoleloggerbridge.cpp \
    src/logger/fileloggerbridge.cpp \
    src/controller/endgamecommand.cpp \
    src/controller/newgamecommand.cpp \
    src/controller/command.cpp \
    src/controller/movecommand.cpp \
    src/logger/consolelogger.cpp \
    src/logger/filelogger.cpp \
    src/logger/loggercontext.cpp \
    src/gameobjects/character.cpp \
    src/gameobjects/gameinteract.cpp \
    src/gameobjects/exitobject.cpp \
    src/gameobjects/coinobject.cpp \
    src/gameobjects/player.cpp \
    src/gameobjects/coinobjectfactory.cpp \
    src/gameobjects/exitobjectfactory.cpp \
    src/controller/gamecontroller.cpp \
    src/model/cell.cpp \
    src/model/field.cpp \
    src/model/gamecell.cpp \
    src/model/gamefield.cpp \
    src/main.cpp \
    src/view/mainwindow.cpp \
    src/utilities/point2d.cpp \
    src/gameobjects/thefttemplate.cpp

HEADERS += \
    inc/gameobjects/enemyabstract.h \
    inc/gameobjects/enemy.h \
    inc/gameobjects/attacktemplate.h \
    inc/gameobjects/debufftemplate.h \
    inc/gameobjects/enemytemplate.h \
    inc/logger/consoleloggerbridge.h \
    inc/logger/fileloggerbridge.h \
    inc/controller/direction.h \
    inc/controller/endgamecommand.h \
    inc/controller/command.h \
    inc/logger/consolelogger.h \
    inc/logger/filelogger.h \
    inc/logger/logger.h \
    inc/logger/loggercontext.h \
    inc/model/cell.h \
    inc/model/field.h \
    inc/model/celltype.h \
    inc/model/gamecell.h \
    inc/model/gamefield.h \
    inc/gameobjects/character.h \
    inc/gameobjects/gameinteract.h \
    inc/gameobjects/exitobject.h \
    inc/gameobjects/coinobject.h \
    inc/gameobjects/gameobject.h \
    inc/gameobjects/player.h \
    inc/gameobjects/coinobjectfactory.h \
    inc/gameobjects/exitobjectfactory.h \
    inc/gameobjects/gameobjectfactory.h \
    inc/gameobjects/interactstrategy.h \
    inc/controller/gamecontroller.h \
    inc/view/mainwindow.h \
    inc/utilities/point2d.h \
    inc/controller/movecommand.h \
    inc/controller/newgamecommand.h \
    inc/logger/loggerbridge.h \
    inc/gameobjects/thefttemplate.h \
    inc/view/objectmapper.h \
    inc/view/levelmapper.h

FORMS += \
    inc/view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
