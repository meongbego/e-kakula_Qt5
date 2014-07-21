QT       += core gui opengl multimedia

TARGET = kakula
TEMPLATE = app

SOURCES += main.cpp\
nastyfft.cpp \
    pulseaudiomonitor.cpp\
spectrumanalyser.cpp\
frequencyspectrum.cpp\
utils.cpp \
    settingsdialog.cpp \
    aboutme.cpp \
    bantuan.cpp \
    latihan.cpp \
    menukakula.cpp \
    mediamusic.cpp \
    menudialog.cpp

HEADERS  +=\
nastyfft.h\
scenepreset.h \
    pulseaudiomonitor.h\
spectrumanalyser.h\
frequencyspectrum.h\
spectrum.h\
utils.h \
    settingsdialog.h \
    aboutme.h \
    bantuan.h \
    latihan.h \
    menukakula.h \
    mediamusic.h \
    menudialog.h

LIBS += -lpulse-simple -lpulse -lGLU


FORMS    += \
    settingsdialog.ui \
    aboutme.ui \
    bantuan.ui \
    latihan.ui \
    menukakula.ui \
    menudialog.ui

fftreal_dir = ../fftreal
INCLUDEPATH += $${fftreal_dir}

LIBS += -L../
LIBS += -lfftreal

# If defined, superimpose the progress bar on the waveform
DEFINES += SUPERIMPOSE_PROGRESS_ON_WAVEFORM

# Perform spectrum analysis calculation in a separate thread
DEFINES += SPECTRUM_ANALYSER_SEPARATE_THREAD

#DEFINES += DUMP_SPECTRUMANALYSER

DESTDIR = ../

        linux-g++*: {
            # Provide relative path from application to fftreal library
            QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN
        }

RESOURCES += \
    resource.qrc

