QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Admin/admintabwidget.cpp \
    Auth_Form/authform.cpp \
    Database/data_test.cpp \
    Database/database.cpp \
    Manager/managertabwidget.cpp \
    Order/orderform.cpp \
    Orders/ordersform.cpp \
    Reg_Form/regform.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Admin/admintabwidget.h \
    Auth_Form/authform.h \
    Database/database.h \
    Manager/managertabwidget.h \
    Order/orderform.h \
    Orders/ordersform.h \
    Reg_Form/regform.h \
    mainwindow.h

FORMS += \
    Admin/admintabwidget.ui \
    Auth_Form/authform.ui \
    Manager/managertabwidget.ui \
    Order/orderform.ui \
    Orders/ordersform.ui \
    Reg_Form/regform.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
