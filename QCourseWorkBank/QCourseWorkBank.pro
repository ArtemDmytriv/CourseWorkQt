#-------------------------------------------------
#
# Project created by QtCreator 2019-05-14T12:05:50
#
#-------------------------------------------------

QT       += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCourseWorkBank
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Account.cpp \
        Bank.cpp \
        Card.cpp \
        Exchanger.cpp \
        SalaryCard.cpp \
        Transaction.cpp \
        UniversalCard.cpp \
        bankchoice.cpp \
        createacc.cpp \
        createcard.cpp \
        func.cpp \
        main.cpp \
        mainwindow.cpp


HEADERS += \
        Account.h \
        Bank.h \
        Card.h \
        Date.h \
        Exchanger.h \
        SalaryCard.h \
        Transaction.h \
        UniversalCard.h \
        bankchoice.h \
        createacc.h \
        createcard.h \
        createform.h \
        func.h \
        head.h \
        mainwindow.h

FORMS += \
        bankchoice.ui \
        createacc.ui \
        createcard.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
