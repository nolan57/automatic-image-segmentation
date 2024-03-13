TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        pieceofimage.cpp \
        #scope.cpp \
        tools.cpp

INCLUDEPATH += /opt/homebrew/Cellar/opencv/4.9.0_4/include/opencv4/
INCLUDEPATH += /opt/homebrew/Cellar/opencv/4.9.0_4/include/opencv4/opencv2/
INCLUDEPATH += /opt/homebrew/Cellar/opencv/4.9.0_4/include/

LIBS += /opt/homebrew/Cellar/opencv/4.9.0_4/lib/libopencv_*

HEADERS += \
    pieceofimage.h \
    #scope.h \
    tools.h
