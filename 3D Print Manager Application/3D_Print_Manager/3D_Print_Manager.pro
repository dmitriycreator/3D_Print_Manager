QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Admin/adminform.cpp \
    Auth_Form/authform.cpp \
    Database/data_test.cpp \
    Database/database.cpp \
    Income/incomeform.cpp \
    Manager/managertabwidget.cpp \
    Order/orderform.cpp \
    Orders/ordersform.cpp \
    Params/paramsform.cpp \
    Reg_Form/regform.cpp \
    Users/usersform.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Admin/adminform.h \
    Auth_Form/authform.h \
    Database/database.h \
    Income/incomeform.h \
    Manager/managertabwidget.h \
    Order/orderform.h \
    Orders/ordersform.h \
    Params/paramsform.h \
    Reg_Form/regform.h \
    Users/usersform.h \
    mainwindow.h

FORMS += \
    Admin/adminform.ui \
    Auth_Form/authform.ui \
    Income/incomeform.ui \
    Manager/managertabwidget.ui \
    Order/orderform.ui \
    Orders/ordersform.ui \
    Params/paramsform.ui \
    Reg_Form/regform.ui \
    Users/usersform.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
