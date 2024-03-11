TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        pieceofimage.cpp \
        tools.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../opencv/build/x64/vc16/lib -lopencv_world490
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../opencv/build/x64/vc16/lib -lopencv_world490d

INCLUDEPATH += $$PWD/../../opencv/build/include
DEPENDPATH += $$PWD/../../opencv/build/include

HEADERS += \
    pieceofimage.h \
    tools.h
