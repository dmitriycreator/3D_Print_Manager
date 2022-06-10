/********************************************************************************
** Form generated from reading UI file 'adminform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINFORM_H
#define UI_ADMINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminForm
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_Users;
    QPushButton *pushButton_Income;
    QPushButton *pushButton_Params;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *AdminForm)
    {
        if (AdminForm->objectName().isEmpty())
            AdminForm->setObjectName(QString::fromUtf8("AdminForm"));
        AdminForm->resize(818, 602);
        gridLayout = new QGridLayout(AdminForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_Users = new QPushButton(AdminForm);
        pushButton_Users->setObjectName(QString::fromUtf8("pushButton_Users"));

        gridLayout->addWidget(pushButton_Users, 0, 0, 1, 1);

        pushButton_Income = new QPushButton(AdminForm);
        pushButton_Income->setObjectName(QString::fromUtf8("pushButton_Income"));

        gridLayout->addWidget(pushButton_Income, 0, 1, 1, 1);

        pushButton_Params = new QPushButton(AdminForm);
        pushButton_Params->setObjectName(QString::fromUtf8("pushButton_Params"));

        gridLayout->addWidget(pushButton_Params, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 3);


        retranslateUi(AdminForm);

        QMetaObject::connectSlotsByName(AdminForm);
    } // setupUi

    void retranslateUi(QWidget *AdminForm)
    {
        AdminForm->setWindowTitle(QCoreApplication::translate("AdminForm", "Form", nullptr));
        pushButton_Users->setText(QCoreApplication::translate("AdminForm", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270...", nullptr));
        pushButton_Income->setText(QCoreApplication::translate("AdminForm", "\320\224\320\276\321\205\320\276\320\264\321\213...", nullptr));
        pushButton_Params->setText(QCoreApplication::translate("AdminForm", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\277\320\265\321\207\320\260\321\202\320\270...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminForm: public Ui_AdminForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINFORM_H
