QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#CONFIG += c++11
CONFIG += c++17

## Mac OS specific qmake options
macx {
TARGET = hw711_Qt_cmidiin
TEMPLATE = app
    CONFIG += app_bundle
    INCLUDEPATH += /Users/je/cs312/common
    INCLUDEPATH += /Library/Frameworks/
    QMAKE_LFLAGS += -F/Library/Frameworks
    QMAKE_CXXFLAGS += -D__MACOSX_CORE__
    LIBS += -framework CoreFoundation \
        -framework CoreMIDI \
        -framework CoreAudio
    QMAKE_CXXFLAGS_WARN_ON += -Wno-unknown-pragmas
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.14
#    ICON = MIDIDisplay.icns
}

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    RtMidi.cpp \
    hw332_CMidiPacket.cpp

HEADERS += \
    mainwindow.h \
    RtMidi.h \
    hw332_CMidiPacket.h
FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
