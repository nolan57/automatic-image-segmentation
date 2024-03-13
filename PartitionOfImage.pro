TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        pieceofimage.cpp \
        tools.cpp


HEADERS += \
    pieceofimage.h \
    tools.h

INCLUDEPATH += E:\openCV\openCV\4.9.0\build\include

LIBS += E:\openCV\4.9.0\bin\libopencv_core490.dll
LIBS += E:\openCV\4.9.0\bin\libopencv_highgui490.dll
LIBS += E:\openCV\4.9.0\bin\libopencv_imgcodecs490.dll
LIBS += E:\openCV\4.9.0\bin\libopencv_imgproc490.dll
LIBS += E:\openCV\4.9.0\bin\libopencv_features2d490.dll
LIBS += E:\openCV\4.9.0\bin\libopencv_calib3d490.dll

