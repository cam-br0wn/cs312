QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


COMMON = /Volumes/COURSES/cs312-00-w20/StuWork/stritzelm/common
LSF = $${COMMON}/libsndfile
RTA = $${COMMON}/RtAudio
ULL = /usr/local/lib
macx {
## JE adds BEGIN
## Mac OS specific qmake options
TARGET = hw911_stats_effects.pro
TEMPLATE = app
    CONFIG += app_bundle
    INCLUDEPATH += $${COMMON}
    INCLUDEPATH += $${COMMON}/libsndfile
    INCLUDEPATH += $${COMMON}/RtAudio
    INCLUDEPATH += /Library/Frameworks/
    QMAKE_LFLAGS += -F/Library/Frameworks
    QMAKE_CXXFLAGS += -D__MACOSX_CORE__
    LIBS += -framework CoreFoundation \
        -framework CoreMIDI \
        -framework CoreAudio \
        $${ULL}/librtaudio.6.1.0.dylib \
        $${ULL}/libsndfile.1.dylib

    QMAKE_CXXFLAGS_WARN_ON += -Wno-unknown-pragmas
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.14
}
## JE adds END

SOURCES += \
    $${RTA}/RtAudio.cpp \
    $${COMMON}/hw411_rand_int.cpp \
    rtaudioutils.cpp \
    waveffects.cpp \
    wavio.cpp \
    wavstats.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    $${LSF}/sndfile.hh \
    $${RTA}/RtAudio.h \
    $${COMMON}/hw411_rand_int.h \
    rtaudioutils.h \
    waveffects.h \
    wavio.h \
    wavstats.h \
    mainwindow.h

FORMS += \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

