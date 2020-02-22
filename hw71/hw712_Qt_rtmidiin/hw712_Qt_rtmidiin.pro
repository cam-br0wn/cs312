QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#CONFIG += c++11
CONFIG += c++17

## Mac OS specific qmake options
macx {
TARGET = hw711_Qt_cmidiin
TEMPLATE = app
    CONFIG += app_bundle
    INCLUDEPATH += /Volumes/cs312-00-w20/StuWork/brownc2/common
    INCLUDEPATH += /Volumes/cs312-00-w20/StuWork/brownc2/common/RtMidi
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

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

RTM = "/Volumes/cs312-00-w20/StuWork/brownc2/common/RtMidi"

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    $${RTM}/RtMidi.cpp \
    hw332_CMidiPacket.cpp

HEADERS += \
    mainwindow.h \
    $${RTM}/RtMidi.h \
    hw332_CMidiPacket.h
FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
