/********************************************************************************
** Form generated from reading UI file 'authform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHFORM_H
#define UI_AUTHFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthForm
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QLabel *label_Auth;
    QLabel *label_Login;
    QLineEdit *lineEdit_Login;
    QLabel *label;
    QLineEdit *lineEdit_Pass;
    QPushButton *pushButton_Log;
    QPushButton *pushButton_Reg;

    void setupUi(QWidget *AuthForm)
    {
        if (AuthForm->objectName().isEmpty())
            AuthForm->setObjectName(QString::fromUtf8("AuthForm"));
        AuthForm->resize(343, 191);
        gridLayout = new QGridLayout(AuthForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(AuthForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));

        gridLayout->addWidget(groupBox, 0, 0, 6, 3);

        label_Auth = new QLabel(AuthForm);
        label_Auth->setObjectName(QString::fromUtf8("label_Auth"));

        gridLayout->addWidget(label_Auth, 1, 2, 1, 1);

        label_Login = new QLabel(AuthForm);
        label_Login->setObjectName(QString::fromUtf8("label_Login"));

        gridLayout->addWidget(label_Login, 2, 1, 1, 1);

        lineEdit_Login = new QLineEdit(AuthForm);
        lineEdit_Login->setObjectName(QString::fromUtf8("lineEdit_Login"));

        gridLayout->addWidget(lineEdit_Login, 2, 2, 1, 1);

        label = new QLabel(AuthForm);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 1, 1, 1);

        lineEdit_Pass = new QLineEdit(AuthForm);
        lineEdit_Pass->setObjectName(QString::fromUtf8("lineEdit_Pass"));
        lineEdit_Pass->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_Pass, 3, 2, 1, 1);

        pushButton_Log = new QPushButton(AuthForm);
        pushButton_Log->setObjectName(QString::fromUtf8("pushButton_Log"));

        gridLayout->addWidget(pushButton_Log, 4, 2, 1, 1);

        pushButton_Reg = new QPushButton(AuthForm);
        pushButton_Reg->setObjectName(QString::fromUtf8("pushButton_Reg"));

        gridLayout->addWidget(pushButton_Reg, 5, 2, 1, 1);


        retranslateUi(AuthForm);

        QMetaObject::connectSlotsByName(AuthForm);
    } // setupUi

    void retranslateUi(QWidget *AuthForm)
    {
        AuthForm->setWindowTitle(QCoreApplication::translate("AuthForm", "Form", nullptr));
        groupBox->setTitle(QString());
        label_Auth->setText(QCoreApplication::translate("AuthForm", "<html><head/><body><p align=\"center\">\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\270\321\200\321\203\320\271\321\202\320\265\321\201\321\214</p></body></html>", nullptr));
        label_Login->setText(QCoreApplication::translate("AuthForm", "<html><head/><body><p align=\"right\">\320\233\320\276\320\263\320\270\320\275 :</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("AuthForm", "<html><head/><body><p align=\"right\">\320\237\320\260\321\200\320\276\320\273\321\214 :</p></body></html>", nullptr));
        pushButton_Log->setText(QCoreApplication::translate("AuthForm", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        pushButton_Reg->setText(QCoreApplication::translate("AuthForm", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthForm: public Ui_AuthForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHFORM_H
