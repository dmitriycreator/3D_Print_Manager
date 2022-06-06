/********************************************************************************
** Form generated from reading UI file 'managertabwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERTABWIDGET_H
#define UI_MANAGERTABWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTabWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerTabWidget
{
public:

    void setupUi(QTabWidget *ManagerTabWidget)
    {
        if (ManagerTabWidget->objectName().isEmpty())
            ManagerTabWidget->setObjectName(QString::fromUtf8("ManagerTabWidget"));
        ManagerTabWidget->resize(400, 300);

        retranslateUi(ManagerTabWidget);

        QMetaObject::connectSlotsByName(ManagerTabWidget);
    } // setupUi

    void retranslateUi(QTabWidget *ManagerTabWidget)
    {
        ManagerTabWidget->setWindowTitle(QCoreApplication::translate("ManagerTabWidget", "TabWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagerTabWidget: public Ui_ManagerTabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERTABWIDGET_H
