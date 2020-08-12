TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        key_detect.cpp \
        keys.cpp \
        main.cpp \
        move.cpp \
        s_input.cpp

HEADERS += \
    defines.h \
    key_detect.h \
    keys.h \
    move.h \
    randomizer.h \
    s_input.h
