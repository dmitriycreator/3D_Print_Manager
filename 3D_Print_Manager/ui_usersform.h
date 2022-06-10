/********************************************************************************
** Form generated from reading UI file 'usersform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSFORM_H
#define UI_USERSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsersForm
{
public:
    QGridLayout *gridLayout_3;
    QToolButton *toolButton_close;
    QLabel *label;
    QTableView *tableView_Users;
    QGroupBox *groupBox_addUser;
    QGridLayout *gridLayout;
    QLabel *label_Name;
    QLineEdit *lineEdit_Name;
    QLabel *label_Pass;
    QLineEdit *lineEdit_Pass;
    QLabel *label_Role;
    QLineEdit *lineEdit_Role;
    QPushButton *pushButton_addUser;
    QGroupBox *groupBox_delUser;
    QGridLayout *gridLayout_2;
    QLabel *label_delLogin;
    QLineEdit *lineEdit_delUser;
    QPushButton *pushButton_delUser;

    void setupUi(QWidget *UsersForm)
    {
        if (UsersForm->objectName().isEmpty())
            UsersForm->setObjectName(QString::fromUtf8("UsersForm"));
        UsersForm->resize(424, 676);
        UsersForm->setMinimumSize(QSize(424, 0));
        gridLayout_3 = new QGridLayout(UsersForm);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        toolButton_close = new QToolButton(UsersForm);
        toolButton_close->setObjectName(QString::fromUtf8("toolButton_close"));

        gridLayout_3->addWidget(toolButton_close, 0, 0, 1, 1);

        label = new QLabel(UsersForm);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        tableView_Users = new QTableView(UsersForm);
        tableView_Users->setObjectName(QString::fromUtf8("tableView_Users"));

        gridLayout_3->addWidget(tableView_Users, 1, 0, 1, 2);

        groupBox_addUser = new QGroupBox(UsersForm);
        groupBox_addUser->setObjectName(QString::fromUtf8("groupBox_addUser"));
        gridLayout = new QGridLayout(groupBox_addUser);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_Name = new QLabel(groupBox_addUser);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));

        gridLayout->addWidget(label_Name, 0, 0, 1, 1);

        lineEdit_Name = new QLineEdit(groupBox_addUser);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));

        gridLayout->addWidget(lineEdit_Name, 0, 1, 1, 1);

        label_Pass = new QLabel(groupBox_addUser);
        label_Pass->setObjectName(QString::fromUtf8("label_Pass"));

        gridLayout->addWidget(label_Pass, 0, 2, 1, 1);

        lineEdit_Pass = new QLineEdit(groupBox_addUser);
        lineEdit_Pass->setObjectName(QString::fromUtf8("lineEdit_Pass"));

        gridLayout->addWidget(lineEdit_Pass, 0, 3, 1, 1);

        label_Role = new QLabel(groupBox_addUser);
        label_Role->setObjectName(QString::fromUtf8("label_Role"));

        gridLayout->addWidget(label_Role, 1, 0, 1, 1);

        lineEdit_Role = new QLineEdit(groupBox_addUser);
        lineEdit_Role->setObjectName(QString::fromUtf8("lineEdit_Role"));

        gridLayout->addWidget(lineEdit_Role, 1, 1, 1, 1);

        pushButton_addUser = new QPushButton(groupBox_addUser);
        pushButton_addUser->setObjectName(QString::fromUtf8("pushButton_addUser"));

        gridLayout->addWidget(pushButton_addUser, 1, 3, 1, 1);


        gridLayout_3->addWidget(groupBox_addUser, 2, 0, 1, 2);

        groupBox_delUser = new QGroupBox(UsersForm);
        groupBox_delUser->setObjectName(QString::fromUtf8("groupBox_delUser"));
        gridLayout_2 = new QGridLayout(groupBox_delUser);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_delLogin = new QLabel(groupBox_delUser);
        label_delLogin->setObjectName(QString::fromUtf8("label_delLogin"));

        gridLayout_2->addWidget(label_delLogin, 0, 0, 1, 1);

        lineEdit_delUser = new QLineEdit(groupBox_delUser);
        lineEdit_delUser->setObjectName(QString::fromUtf8("lineEdit_delUser"));

        gridLayout_2->addWidget(lineEdit_delUser, 0, 1, 1, 1);

        pushButton_delUser = new QPushButton(groupBox_delUser);
        pushButton_delUser->setObjectName(QString::fromUtf8("pushButton_delUser"));

        gridLayout_2->addWidget(pushButton_delUser, 0, 2, 1, 1);


        gridLayout_3->addWidget(groupBox_delUser, 3, 0, 1, 2);


        retranslateUi(UsersForm);

        QMetaObject::connectSlotsByName(UsersForm);
    } // setupUi

    void retranslateUi(QWidget *UsersForm)
    {
        UsersForm->setWindowTitle(QCoreApplication::translate("UsersForm", "Form", nullptr));
        toolButton_close->setText(QCoreApplication::translate("UsersForm", "X", nullptr));
        label->setText(QCoreApplication::translate("UsersForm", "<html><head/><body><p align=\"center\">\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270</p></body></html>", nullptr));
        groupBox_addUser->setTitle(QCoreApplication::translate("UsersForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_Name->setText(QCoreApplication::translate("UsersForm", "<html><head/><body><p align=\"right\">\320\233\320\276\320\263\320\270\320\275 :</p></body></html>", nullptr));
        label_Pass->setText(QCoreApplication::translate("UsersForm", "<html><head/><body><p align=\"right\">\320\237\320\260\321\200\320\276\320\273\321\214 :</p></body></html>", nullptr));
        label_Role->setText(QCoreApplication::translate("UsersForm", "<html><head/><body><p align=\"right\">\320\240\320\276\320\273\321\214 :</p></body></html>", nullptr));
        pushButton_addUser->setText(QCoreApplication::translate("UsersForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        groupBox_delUser->setTitle(QCoreApplication::translate("UsersForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_delLogin->setText(QCoreApplication::translate("UsersForm", "<html><head/><body><p align=\"right\">\320\233\320\276\320\263\320\270\320\275 :</p></body></html>", nullptr));
        pushButton_delUser->setText(QCoreApplication::translate("UsersForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsersForm: public Ui_UsersForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSFORM_H
