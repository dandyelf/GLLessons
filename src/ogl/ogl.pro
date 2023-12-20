QT       += core gui opengl
mac: QT += openglwidgets
linux: QT += openglwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../model/s21_aff_transform.cc \
    ../model/s21_facade_obj.cc \
    ../model/s21_parser_obj.cc \
    main.cc \
    mainwindow.cc \
    paint.cc

HEADERS += \
    ../controller/s21_controller_obj.h \
    ../model/s21_aff_transform.h \
    ../model/s21_facade_obj.h \
    ../model/s21_parser_obj.h \
    mainwindow.h \
    paint.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
