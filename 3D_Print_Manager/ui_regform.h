/********************************************************************************
** Form generated from reading UI file 'regform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGFORM_H
#define UI_REGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegForm
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QLabel *label_Reg;
    QLabel *label_Name;
    QLineEdit *lineEdit_Name;
    QLabel *label_Pass;
    QLineEdit *lineEdit_Pass;
    QLabel *label_Cofirm;
    QLineEdit *lineEdit_Confirm;
    QPushButton *pushButton_Back;
    QPushButton *pushButton_Create;

    void setupUi(QWidget *RegForm)
    {
        if (RegForm->objectName().isEmpty())
            RegForm->setObjectName(QString::fromUtf8("RegForm"));
        RegForm->resize(463, 190);
        gridLayout = new QGridLayout(RegForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(RegForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));

        gridLayout->addWidget(groupBox, 0, 0, 6, 3);

        label_Reg = new QLabel(RegForm);
        label_Reg->setObjectName(QString::fromUtf8("label_Reg"));

        gridLayout->addWidget(label_Reg, 1, 2, 1, 1);

        label_Name = new QLabel(RegForm);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));

        gridLayout->addWidget(label_Name, 2, 1, 1, 1);

        lineEdit_Name = new QLineEdit(RegForm);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));

        gridLayout->addWidget(lineEdit_Name, 2, 2, 1, 1);

        label_Pass = new QLabel(RegForm);
        label_Pass->setObjectName(QString::fromUtf8("label_Pass"));

        gridLayout->addWidget(label_Pass, 3, 1, 1, 1);

        lineEdit_Pass = new QLineEdit(RegForm);
        lineEdit_Pass->setObjectName(QString::fromUtf8("lineEdit_Pass"));
        lineEdit_Pass->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_Pass, 3, 2, 1, 1);

        label_Cofirm = new QLabel(RegForm);
        label_Cofirm->setObjectName(QString::fromUtf8("label_Cofirm"));

        gridLayout->addWidget(label_Cofirm, 4, 1, 1, 1);

        lineEdit_Confirm = new QLineEdit(RegForm);
        lineEdit_Confirm->setObjectName(QString::fromUtf8("lineEdit_Confirm"));
        lineEdit_Confirm->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_Confirm, 4, 2, 1, 1);

        pushButton_Back = new QPushButton(RegForm);
        pushButton_Back->setObjectName(QString::fromUtf8("pushButton_Back"));

        gridLayout->addWidget(pushButton_Back, 5, 1, 1, 1);

        pushButton_Create = new QPushButton(RegForm);
        pushButton_Create->setObjectName(QString::fromUtf8("pushButton_Create"));

        gridLayout->addWidget(pushButton_Create, 5, 2, 1, 1);


        retranslateUi(RegForm);

        QMetaObject::connectSlotsByName(RegForm);
    } // setupUi

    void retranslateUi(QWidget *RegForm)
    {
        RegForm->setWindowTitle(QCoreApplication::translate("RegForm", "Form", nullptr));
        groupBox->setTitle(QString());
        label_Reg->setText(QCoreApplication::translate("RegForm", "<html><head/><body><p align=\"center\">\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260</p></body></html>", nullptr));
        label_Name->setText(QCoreApplication::translate("RegForm", "<html><head/><body><p align=\"right\">\320\230\320\274\321\217 :</p></body></html>", nullptr));
        label_Pass->setText(QCoreApplication::translate("RegForm", "<html><head/><body><p align=\"right\">\320\237\320\260\321\200\320\276\320\273\321\214 :</p></body></html>", nullptr));
        label_Cofirm->setText(QCoreApplication::translate("RegForm", "<html><head/><body><p align=\"right\">\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\320\265 :</p></body></html>", nullptr));
        pushButton_Back->setText(QCoreApplication::translate("RegForm", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        pushButton_Create->setText(QCoreApplication::translate("RegForm", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegForm: public Ui_RegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGFORM_H
