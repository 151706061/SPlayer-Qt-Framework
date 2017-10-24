#-------------------------------------------------
#
# Project created by QtCreator 2017-04-23T18:07:10
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SPlayer
TEMPLATE = app

LIBS += \
    -lDwmapi \
    -lUser32

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

#PRECOMPILED_HEADER = PCH.h

DESTDIR = $$PWD/bin

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = resource/Player.ico

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    StandardDialog/StandardDialog.cpp \
    StandardDialog/StandardHeader.cpp \
    Control/BaseWidget.cpp \
    Control/SButton.cpp \
    WindowManager.cpp \
    Style/SStyle.cpp \
    StandardDialog/StandardBottom.cpp \
    LogoWidget.cpp \
    WindowBottom.cpp \
    Control/SProgressBar.cpp \
    ConfigDialog.cpp \
    Control/DraggableWidget.cpp \
    Control/framelesswindow.cpp

HEADERS += \
    mainwindow.h \
    StandardDialog/StandardDialog.h \
    StandardDialog/StandardHeader.h \
    Control/BaseWidget.h \
    Control/ObjectFourTuple.h \
    Control/SButton.h \
    WindowManager.h \
    #PCH.h \
    Style/SStyle.h \
    StandardDialog/StandardBottom.h \
    LogoWidget.h \
    WindowBottom.h \
    Control/SProgressBar.h \
    ConfigDialog.h \
    Control/DraggableWidget.h \
    Control/framelesswindow.h

RESOURCES += \
    res.qrc
