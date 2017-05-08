#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T10:25:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Raytracer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES +=\
    rtvector3d.cpp \
    rtvector2d.cpp \
    rtray.cpp \
    rtmain.cpp \
    rtobject.cpp \
    rtsphere.cpp \
    rtplane.cpp \
    rtraywindow.cpp \
    rtimagewindow.cpp \
    rtlightintensity.cpp \
    rtfilm.cpp \
    rtabstractcamera.cpp \
    rtperspectivecamera.cpp \
    rtortographiccamera.cpp \
    rtmesh.cpp \
    rtmaterial.cpp \
    rtphong.cpp \
    rtabstractlight.cpp \
    rtomnilight.cpp \
    rtambientlight.cpp \
    rtdirectionallight.cpp \
    rtarealight.cpp \
    rtpixelthread.cpp \
    rtperspectivecameramultithread.cpp \
    rtphongtextured.cpp

HEADERS  += \
    rtvector3d.h \
    rtvector2d.h \
    rtray.h \
    rtobject.h \
    rtsphere.h \
    rtplane.h \
    rtraywindow.h \
    rtimagewindow.h \
    rtlightintensity.h \
    rtfilm.h \
    rtabstractcamera.h \
    rtperspectivecamera.h \
    rtortographiccamera.h \
    rtmesh.h \
    rtmaterial.h \
    rtphong.h \
    rtabstractlight.h \
    rtomnilight.h \
    rtambientlight.h \
    rtdirectionallight.h \
    rtarealight.h \
    rtpixelthread.h \
    rtperspectivecameramultithread.h \
    rtphongtextured.h

FORMS    += \
    rtraywindow.ui \
    rtimagewindow.ui
test {
message(test build)
    QT += testlib
    TARGET = UnitTests
    SOURCES -= rtmain.cpp
    SOURCES += rtTest/rttestmain.cpp \
    rtTest/rttestvector3d.cpp \
    rtTest/rttestsphere.cpp \
    rtTest/rttestray.cpp \
    rtTest/rttestplane.cpp

    HEADERS +=   rtTest/rttestvector3d.h \
    rtTest/rttestsphere.h \
    rtTest/rttestray.h \
    rtTest/rttestplane.h
}
else{
    message(normal build)
}
