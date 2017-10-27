TEMPLATE = subdirs

SUBDIRS += \
    Qt-Nice-Frameless-Window \
    SPlayer

SPlayer.depends = Qt-Nice-Frameless-Window

CONFIG += ordered