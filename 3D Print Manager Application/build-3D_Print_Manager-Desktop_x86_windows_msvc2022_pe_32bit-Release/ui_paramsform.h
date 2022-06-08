/********************************************************************************
** Form generated from reading UI file 'paramsform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMSFORM_H
#define UI_PARAMSFORM_H

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

class Ui_ParamsForm
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_delPlastic;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_delPlastic;
    QLineEdit *lineEdit_Del;
    QLabel *label_Del;
    QTableView *tableView_Params;
    QToolButton *toolButton_close;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_AddPlastic;
    QLineEdit *lineEdit_Name;
    QLabel *label_Cost;
    QLineEdit *lineEdit_Cost;
    QLabel *label_Name;
    QLabel *label;
    QLabel *label_Info;

    void setupUi(QWidget *ParamsForm)
    {
        if (ParamsForm->objectName().isEmpty())
            ParamsForm->setObjectName(QString::fromUtf8("ParamsForm"));
        ParamsForm->resize(671, 642);
        gridLayout_3 = new QGridLayout(ParamsForm);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_delPlastic = new QGroupBox(ParamsForm);
        groupBox_delPlastic->setObjectName(QString::fromUtf8("groupBox_delPlastic"));
        gridLayout_2 = new QGridLayout(groupBox_delPlastic);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_delPlastic = new QPushButton(groupBox_delPlastic);
        pushButton_delPlastic->setObjectName(QString::fromUtf8("pushButton_delPlastic"));

        gridLayout_2->addWidget(pushButton_delPlastic, 0, 2, 1, 1);

        lineEdit_Del = new QLineEdit(groupBox_delPlastic);
        lineEdit_Del->setObjectName(QString::fromUtf8("lineEdit_Del"));

        gridLayout_2->addWidget(lineEdit_Del, 0, 1, 1, 1);

        label_Del = new QLabel(groupBox_delPlastic);
        label_Del->setObjectName(QString::fromUtf8("label_Del"));

        gridLayout_2->addWidget(label_Del, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_delPlastic, 5, 0, 1, 2);

        tableView_Params = new QTableView(ParamsForm);
        tableView_Params->setObjectName(QString::fromUtf8("tableView_Params"));

        gridLayout_3->addWidget(tableView_Params, 2, 0, 1, 2);

        toolButton_close = new QToolButton(ParamsForm);
        toolButton_close->setObjectName(QString::fromUtf8("toolButton_close"));

        gridLayout_3->addWidget(toolButton_close, 0, 0, 1, 1);

        groupBox = new QGroupBox(ParamsForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_AddPlastic = new QPushButton(groupBox);
        pushButton_AddPlastic->setObjectName(QString::fromUtf8("pushButton_AddPlastic"));

        gridLayout->addWidget(pushButton_AddPlastic, 2, 2, 1, 1);

        lineEdit_Name = new QLineEdit(groupBox);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));

        gridLayout->addWidget(lineEdit_Name, 1, 1, 1, 1);

        label_Cost = new QLabel(groupBox);
        label_Cost->setObjectName(QString::fromUtf8("label_Cost"));

        gridLayout->addWidget(label_Cost, 1, 2, 1, 1);

        lineEdit_Cost = new QLineEdit(groupBox);
        lineEdit_Cost->setObjectName(QString::fromUtf8("lineEdit_Cost"));

        gridLayout->addWidget(lineEdit_Cost, 1, 3, 1, 1);

        label_Name = new QLabel(groupBox);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));

        gridLayout->addWidget(label_Name, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 3, 0, 1, 2);

        label = new QLabel(ParamsForm);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        label_Info = new QLabel(ParamsForm);
        label_Info->setObjectName(QString::fromUtf8("label_Info"));

        gridLayout_3->addWidget(label_Info, 6, 0, 1, 2);


        retranslateUi(ParamsForm);

        QMetaObject::connectSlotsByName(ParamsForm);
    } // setupUi

    void retranslateUi(QWidget *ParamsForm)
    {
        ParamsForm->setWindowTitle(QCoreApplication::translate("ParamsForm", "Form", nullptr));
        groupBox_delPlastic->setTitle(QCoreApplication::translate("ParamsForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\273\320\260\321\201\321\202\320\270\320\272", nullptr));
        pushButton_delPlastic->setText(QCoreApplication::translate("ParamsForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_Del->setText(QCoreApplication::translate("ParamsForm", "<html><head/><body><p align=\"right\">\320\230\320\274\321\217 :</p></body></html>", nullptr));
        toolButton_close->setText(QCoreApplication::translate("ParamsForm", "X", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ParamsForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\273\320\260\321\201\321\202\320\270\320\272", nullptr));
        pushButton_AddPlastic->setText(QCoreApplication::translate("ParamsForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_Cost->setText(QCoreApplication::translate("ParamsForm", "<html><head/><body><p align=\"right\">\320\246\320\265\320\275\320\260 \320\267\320\260 \320\263\321\200\320\260\320\274\320\274 :</p></body></html>", nullptr));
        label_Name->setText(QCoreApplication::translate("ParamsForm", "<html><head/><body><p align=\"right\">\320\230\320\274\321\217 :</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("ParamsForm", "<html><head/><body><p align=\"center\">\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\277\320\265\321\207\320\260\321\202\320\270</p></body></html>", nullptr));
        label_Info->setText(QCoreApplication::translate("ParamsForm", "\320\237\320\276\321\201\320\273\320\265 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\270 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\321\217 \320\277\320\273\320\260\321\201\321\202\320\270\320\272\320\276\320\262 \320\276\321\202\320\272\321\200\321\213\321\202\321\213\320\265 \320\267\320\260\320\272\320\260\320\267\321\213 \320\267\320\260\320\272\321\200\320\276\320\271\321\202\320\265 \320\270 \320\276\321\202\320\272\321\200\320\276\320\271\321\202\320\265 \320\267\320\260\320\275\320\276\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParamsForm: public Ui_ParamsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMSFORM_H
