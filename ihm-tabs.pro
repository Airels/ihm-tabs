QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    activatefiltermanager.cpp \
    cell.cpp \
    conditionalcolordialog.cpp \
    datamanager.cpp \
    filemanager.cpp \
    filter.cpp \
    fixedcolordialog.cpp \
    fixedcolorfilter.cpp \
    gradientcolordialog.cpp \
    main.cpp \
    mainwindow.cpp \
    minmaxfilter.cpp \
    modulocolordialog.cpp \
    modulofilter.cpp \
    simplifiedconditionfilter.cpp \
    sortdialog.cpp \
    tablewidget.cpp \
    viewmanager.cpp

HEADERS += \
    activatefiltermanager.h \
    cell.h \
    conditionalcolordialog.h \
    datamanager.h \
    filemanager.h \
    filter.h \
    fixedcolordialog.h \
    fixedcolorfilter.h \
    gradientcolordialog.h \
    mainwindow.h \
    minmaxfilter.h \
    modulocolordialog.h \
    modulofilter.h \
    simplifiedconditionfilter.h \
    sortdialog.h \
    tablewidget.h \
    viewmanager.h

FORMS += \
    conditionalcolordialog.ui \
    fixedcolordialog.ui \
    gradientcolordialog.ui \
    mainwindow.ui \
    modulocolordialog.ui \
    sortdialog.ui \
    tablewidget.ui

RESOURCES += resources.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
