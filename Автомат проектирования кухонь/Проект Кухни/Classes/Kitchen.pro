QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BackWall.cpp \
    Cabinet.cpp \
    CashPriemnik.cpp \
    CupBoard.cpp \
    DSP.cpp \
    Detail.cpp \
    Fasade.cpp \
    Groove.cpp \
    Holes.cpp \
    Material.cpp \
    MaterialBASE.cpp \
    Modules.cpp \
    TempBASE.cpp \
    iKitchen.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    BackWall.h \
    Cabinet.h \
    CashPriemnik.h \
    CupBoard.h \
    DSP.h \
    Detail.h \
    Fasade.h \
    Groove.h \
    Holes.h \
    Material.h \
    MaterialBASE.h \
    Modules.h \
    TempBASE.h \
    iKitchen.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
