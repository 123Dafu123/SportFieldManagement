QT       += core gui
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BLL/logbll.cpp \
    BLL/mbrbll.cpp \
    BLL/mgrbll.cpp \
    BLL/regbll.cpp \
    BLL/sysbll.cpp \
    DAL/dbconnection.cpp \
    DAL/logdao.cpp \
    DAL/mbrdao.cpp \
    DAL/mgrdao.cpp \
    DAL/regdao.cpp \
    DAL/sysdao.cpp \
    Ui\logform.cpp \
    main.cpp \
    Ui\mbrwindow.cpp \
    Ui\mgrwindow.cpp \
    Ui\regform.cpp \
    Ui\syswindow.cpp

HEADERS += \
    BLL/logbll.h \
    BLL/mbrbll.h \
    BLL/mgrbll.h \
    BLL/regbll.h \
    BLL/sysbll.h \
    DAL/dbconnection.h \
    DAL/logdao.h \
    DAL/mbrdao.h \
    DAL/mgrdao.h \
    DAL/regdao.h \
    DAL/sysdao.h \
    Ui\logform.h \
    Ui\mbrwindow.h \
    Ui\mgrwindow.h \
    Ui\regform.h \
    Ui\syswindow.h

FORMS += \
    logform.ui \
    mbrwindow.ui \
    mgrwindow.ui \
    regform.ui \
    syswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recourse.qrc
