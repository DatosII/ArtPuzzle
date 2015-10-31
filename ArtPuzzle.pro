#-------------------------------------------------
#
# Project created by QtCreator 2015-10-30T16:24:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArtPuzzle
TEMPLATE = app


SOURCES += main.cpp\
    Facade/facade.cpp \
    GUI/menuprincipal.cpp \
    GUI/ventanaayuda.cpp \
    GUI/ventanacaptura.cpp \
    Logic/algoritmoavido.cpp \
    GUI/ventanadesordenada.cpp \
    GUI/ventanafinal.cpp \
    Logic/desordenarimagen.cpp

HEADERS  += Facade/facade.h \
    GUI/menuprincipal.h \
    GUI/ventanaayuda.h \
    GUI/ventanacaptura.h \
    Logic/algoritmoavido.h \
    GUI/ventanadesordenada.h \
    GUI/ventanafinal.h \
    Logic/desordenarimagen.h \
    Logic/constansLogic.h

RESOURCES += \
    Resources.qrc

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core -lopencv_hal

CONFIG += C++11
