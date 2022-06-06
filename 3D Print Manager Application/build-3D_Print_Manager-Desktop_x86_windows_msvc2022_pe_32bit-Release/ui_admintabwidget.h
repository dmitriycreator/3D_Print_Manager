/********************************************************************************
** Form generated from reading UI file 'admintabwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINTABWIDGET_H
#define UI_ADMINTABWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTabWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminTabWidget
{
public:

    void setupUi(QTabWidget *AdminTabWidget)
    {
        if (AdminTabWidget->objectName().isEmpty())
            AdminTabWidget->setObjectName(QString::fromUtf8("AdminTabWidget"));
        AdminTabWidget->resize(400, 300);

        retranslateUi(AdminTabWidget);

        QMetaObject::connectSlotsByName(AdminTabWidget);
    } // setupUi

    void retranslateUi(QTabWidget *AdminTabWidget)
    {
        AdminTabWidget->setWindowTitle(QCoreApplication::translate("AdminTabWidget", "TabWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminTabWidget: public Ui_AdminTabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINTABWIDGET_H
