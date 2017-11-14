QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SPlayer
TEMPLATE = app

include($$PWD/../Qt-Nice-Frameless-Window/projectinclude/common.pri)

DESTDIR = $$PWD/../bin

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

VERSION = 1.0.0.0
RC_ICONS = resource/Player.ico
RC_LANG = 0x0004
QMAKE_TARGET_COMPANY = "wangwenx190"
QMAKE_TARGET_COPYRIGHT = "Copyright (C) 2017 by wangwenx190. All rights reserved."
QMAKE_TARGET_DESCRIPTION = "SPlayer - Enjoy the simple life"
QMAKE_TARGET_PRODUCT = "SPlayer"

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
    ConfigDialog.cpp

HEADERS += \
    mainwindow.h \
    StandardDialog/StandardDialog.h \
    StandardDialog/StandardHeader.h \
    Control/BaseWidget.h \
    Control/ObjectFourTuple.h \
    Control/SButton.h \
    WindowManager.h \
    Style/SStyle.h \
    StandardDialog/StandardBottom.h \
    LogoWidget.h \
    WindowBottom.h \
    Control/SProgressBar.h \
    ConfigDialog.h

RESOURCES += \
    res.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Qt-Nice-Frameless-Window/framelesswindow/release/ -lframelesswindow
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Qt-Nice-Frameless-Window/framelesswindow/debug/ -lframelesswindow
else:macx: LIBS += -L$$OUT_PWD/../Qt-Nice-Frameless-Window/framelesswindow/ -lframelesswindow

INCLUDEPATH += $$PWD/../Qt-Nice-Frameless-Window/framelesswindow
DEPENDPATH += $$PWD/../Qt-Nice-Frameless-Window/framelesswindow

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Qt-Nice-Frameless-Window/framelesswindow/release/libframelesswindow.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Qt-Nice-Frameless-Window/framelesswindow/debug/libframelesswindow.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Qt-Nice-Frameless-Window/framelesswindow/release/framelesswindow.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Qt-Nice-Frameless-Window/framelesswindow/debug/framelesswindow.lib
else:macx: PRE_TARGETDEPS += $$OUT_PWD/../Qt-Nice-Frameless-Window/framelesswindow/libframelesswindow.a
