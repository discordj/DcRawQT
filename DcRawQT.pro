# -------------------------------------------------
# Project created by QtCreator 2009-07-30T14:24:28
# -------------------------------------------------
# QT -= gui
TARGET = DcRawQT
TEMPLATE = lib
INCLUDEPATH = ../CImg /usr/local/include
DEFINES += DCRAWQT_LIBRARY \
    __MINGW__ \
    NO_JPEG \
    USE_CIMG
win32 { 
    DEFINES += WIN32 \
        DJGPP
    LIBS += -lws2_32
}
!win32 {
    LIBS += -L/usr/local/lib -llcms
}
SOURCES += dcrawqt.cpp \
    dcraw.cpp \
    dcrawqtoptions.cpp \
    dcrimage.cpp
HEADERS += dcrawqt.h \
    dcraw.h \
    dcrawqtoptions.h \
    dcrawqt_global.h \
    dcrimage.h
FORMS += dcrawqtoptions.ui
