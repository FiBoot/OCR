#-------------------------------------------------
#
# Project created by QtCreator 2013-11-12T12:55:00
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = LearningANN
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    bitmap.cpp  \
    fixedfann.c \
    fann_train_data.c \
    fann_train.c \
    fann_io.c \
    fann_error.c \
    fann_cascade.c \
    fann.c \
    learningprocess.cpp


HEADERS += \
    bitmap.h    \
    fixedfann.h \
    fann_train.h \
    fann_io.h \
    fann_internal.h \
    fann_error.h \
    fann_data.h \
    fann_cpp.h \
    fann_cascade.h \
    fann_activation.h \
    fann.h \
    config.h \
    compat_time.h \
    learningprocess.h

win32:LIBS += C:\Users\ASUS\workspace\OCR\trunk\FANN-2.2.0-Source\bin\fannfixed.dll
