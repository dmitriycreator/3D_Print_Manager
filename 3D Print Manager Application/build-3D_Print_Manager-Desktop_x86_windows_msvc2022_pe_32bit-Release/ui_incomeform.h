/********************************************************************************
** Form generated from reading UI file 'incomeform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCOMEFORM_H
#define UI_INCOMEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IncomeForm
{
public:
    QGridLayout *gridLayout;
    QToolButton *toolButton_close;
    QLabel *label_Income;
    QPushButton *pushButton_refresh;
    QPushButton *pushButton_AllIncome;
    QTableView *tableView_Income;

    void setupUi(QWidget *IncomeForm)
    {
        if (IncomeForm->objectName().isEmpty())
            IncomeForm->setObjectName(QString::fromUtf8("IncomeForm"));
        IncomeForm->resize(417, 626);
        IncomeForm->setMinimumSize(QSize(417, 0));
        gridLayout = new QGridLayout(IncomeForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        toolButton_close = new QToolButton(IncomeForm);
        toolButton_close->setObjectName(QString::fromUtf8("toolButton_close"));

        gridLayout->addWidget(toolButton_close, 0, 0, 1, 1);

        label_Income = new QLabel(IncomeForm);
        label_Income->setObjectName(QString::fromUtf8("label_Income"));

        gridLayout->addWidget(label_Income, 0, 1, 1, 1);

        pushButton_refresh = new QPushButton(IncomeForm);
        pushButton_refresh->setObjectName(QString::fromUtf8("pushButton_refresh"));

        gridLayout->addWidget(pushButton_refresh, 1, 0, 1, 2);

        pushButton_AllIncome = new QPushButton(IncomeForm);
        pushButton_AllIncome->setObjectName(QString::fromUtf8("pushButton_AllIncome"));

        gridLayout->addWidget(pushButton_AllIncome, 2, 0, 1, 2);

        tableView_Income = new QTableView(IncomeForm);
        tableView_Income->setObjectName(QString::fromUtf8("tableView_Income"));

        gridLayout->addWidget(tableView_Income, 3, 0, 1, 2);


        retranslateUi(IncomeForm);

        QMetaObject::connectSlotsByName(IncomeForm);
    } // setupUi

    void retranslateUi(QWidget *IncomeForm)
    {
        IncomeForm->setWindowTitle(QCoreApplication::translate("IncomeForm", "Form", nullptr));
        toolButton_close->setText(QCoreApplication::translate("IncomeForm", "X", nullptr));
        label_Income->setText(QCoreApplication::translate("IncomeForm", "<html><head/><body><p align=\"center\">\320\224\320\276\321\205\320\276\320\264\321\213</p></body></html>", nullptr));
        pushButton_refresh->setText(QCoreApplication::translate("IncomeForm", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        pushButton_AllIncome->setText(QCoreApplication::translate("IncomeForm", "\320\236\320\261\321\211\320\270\320\271 \320\264\320\276\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IncomeForm: public Ui_IncomeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOMEFORM_H
