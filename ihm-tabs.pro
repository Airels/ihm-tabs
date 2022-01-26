QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cell.cpp \
    datamanager.cpp \
    filemanager.cpp \
    filter.cpp \
    fixedcolorfilter.cpp \
    main.cpp \
    mainwindow.cpp \
    minmaxfilter.cpp \
    modulofilter.cpp \
    simplifiedconditionfilter.cpp \
    tablewidget.cpp \
    viewmanager.cpp

HEADERS += \
    cell.h \
    datamanager.h \
    filemanager.h \
    filter.h \
    fixedcolorfilter.h \
    mainwindow.h \
    minmaxfilter.h \
    modulofilter.h \
    simplifiedconditionfilter.h \
    tablewidget.h \
    viewmanager.h

FORMS += \
    mainwindow.ui \
    tablewidget.ui

RESOURCES += resources.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
