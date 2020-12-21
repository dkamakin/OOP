QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
INCLUDEPATH += $$PWD/inc

SOURCES += \
    src/exceptions/archiveexception.cpp \
    src/view/faqwindow.cpp \
    src/view/levelmapper.cpp \
    src/view/objectmapper.cpp \
    src/view/mainwindow.cpp \
    src/logger/logger.cpp \
    src/logger/consoleloggerbridge.cpp \
    src/logger/fileloggerbridge.cpp \
    src/logger/consolelogger.cpp \
    src/logger/filelogger.cpp \
    src/logger/loggercontext.cpp \
    src/controller/commands/loadcommand.cpp \
    src/controller/commands/savecommand.cpp \
    src/controller/archive/loader.cpp \
    src/controller/archive/saver.cpp \
    src/controller/archive/enemymemento.cpp \
    src/controller/archive/fieldmemento.cpp \
    src/controller/archive/playermemento.cpp \
    src/controller/commands/endgamecommand.cpp \
    src/controller/archive/cellmemento.cpp \
    src/controller/commands/newgamecommand.cpp \
    src/controller/commands/command.cpp \
    src/controller/commands/movecommand.cpp \
    src/controller/commands/attackcommand.cpp \
    src/controller/states/enemyturnstate.cpp \
    src/controller/states/playerturnstate.cpp \
    src/controller/gamecontroller.cpp \
    src/gameobjects/characters/attacktemplate.cpp \
    src/gameobjects/characters/debufftemplate.cpp \
    src/gameobjects/characters/character.cpp \
    src/gameobjects/gameinteract.cpp \
    src/gameobjects/exit/exitobject.cpp \
    src/gameobjects/coin/coinobject.cpp \
    src/gameobjects/characters/player.cpp \
    src/gameobjects/coin/coinobjectfactory.cpp \
    src/gameobjects/sword/swordobject.cpp \
    src/gameobjects/sword/swordobjectfactory.cpp \
    src/gameobjects/exit/exitobjectfactory.cpp \
    src/gameobjects/characters/thefttemplate.cpp \
    src/model/gamecell.cpp \
    src/model/gamefield.cpp \
    src/model/fieldmapper.cpp \
    src/main.cpp \
    src/utilities/point2d.cpp

HEADERS += \
    inc/exceptions/archiveexception.h \
    inc/controller/archive/cellmemento.h \
    inc/controller/archive/filestructure.h \
    inc/controller/archive/enemymemento.h \
    inc/controller/archive/fieldmemento.h \
    inc/controller/commands/attackcommand.h \
    inc/controller/states/controllerstate.h \
    inc/controller/states/enemyturnstate.h \
    inc/controller/direction.h \
    inc/controller/commands/movecommand.h \
    inc/controller/commands/newgamecommand.h \
    inc/controller/commands/endgamecommand.h \
    inc/controller/states/playerturnstate.h \
    inc/controller/commands/command.h \
    inc/controller/gamecontroller.h \
    inc/logger/consolelogger.h \
    inc/logger/filelogger.h \
    inc/logger/logger.h \
    inc/logger/loggerbridge.h \
    inc/logger/loggercontext.h \
    inc/logger/consoleloggerbridge.h \
    inc/logger/fileloggerbridge.h \
    inc/model/celltype.h \
    inc/model/gamecell.h \
    inc/model/fieldmapper.h \
    inc/model/gamefield.h \
    inc/gameobjects/characters/character.h \
    inc/gameobjects/characters/enemyabstract.h \
    inc/gameobjects/characters/enemy.h \
    inc/gameobjects/characters/attacktemplate.h \
    inc/gameobjects/characters/debufftemplate.h \
    inc/gameobjects/characters/enemytemplate.h \
    inc/gameobjects/gameinteract.h \
    inc/gameobjects/exit/exitobject.h \
    inc/gameobjects/coin/coinobject.h \
    inc/gameobjects/gameobject.h \
    inc/gameobjects/characters/player.h \
    inc/gameobjects/coin/coinobjectfactory.h \
    inc/gameobjects/exit/exitobjectfactory.h \
    inc/gameobjects/gameobjectfactory.h \
    inc/gameobjects/characters/interactstrategy.h \
    inc/gameobjects/sword/swordobject.h \
    inc/gameobjects/sword/swordobjectfactory.h \
    inc/gameobjects/characters/thefttemplate.h \
    inc/utilities/point2d.h \
    inc/view/objectmapper.h \
    inc/view/mainwindow.h \
    inc/view/levelmapper.h \
    inc/view/faqwindow.h \
    inc/controller/archive/playermemento.h \
    inc/controller/archive/loader.h \
    inc/controller/archive/saver.h \
    inc/controller/commands/loadcommand.h \
    inc/controller/commands/savecommand.h

FORMS += \
    inc/view/faqwindow.ui \
    inc/view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
