#-------------------------------------------------
#
# Project created by QtCreator 2013-10-25T01:08:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OCR
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bitmap.cpp \
    fixedfann.c \
    fann_train_data.c \
    fann_train.c \
    fann_io.c \
    fann_error.c \
    fann_cascade.c \
    fann.c

HEADERS  += mainwindow.h \
    bitmap.h \
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
    compat_time.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    OCR.pro.user
