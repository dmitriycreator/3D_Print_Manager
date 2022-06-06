/********************************************************************************
** Form generated from reading UI file 'orderform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERFORM_H
#define UI_ORDERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderForm
{
public:
    QGridLayout *gridLayout_3;
    QToolButton *toolButton_close;
    QLabel *label_Order;
    QTableView *tableView_Order;
    QGroupBox *groupBox_Add;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_addAmount;
    QLabel *label_addAmount;
    QComboBox *comboBox_Plastic;
    QLabel *label_addName;
    QLineEdit *lineEdit_addName;
    QLabel *label_Plastic;
    QLabel *label_Weight;
    QPushButton *pushButton_addPrint;
    QDoubleSpinBox *doubleSpinBox_addWeight;
    QLabel *label_Time;
    QDoubleSpinBox *doubleSpinBox_addTime;
    QDoubleSpinBox *doubleSpinBox_PremiumRate;
    QLabel *label_PR;
    QCheckBox *checkBox_Done;
    QCheckBox *checkBox_Defective;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_ID;
    QLineEdit *lineEdit_deleteID;
    QPushButton *pushButton_deletePrint;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *OrderForm)
    {
        if (OrderForm->objectName().isEmpty())
            OrderForm->setObjectName(QString::fromUtf8("OrderForm"));
        OrderForm->resize(747, 991);
        gridLayout_3 = new QGridLayout(OrderForm);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        toolButton_close = new QToolButton(OrderForm);
        toolButton_close->setObjectName(QString::fromUtf8("toolButton_close"));

        gridLayout_3->addWidget(toolButton_close, 0, 0, 1, 1);

        label_Order = new QLabel(OrderForm);
        label_Order->setObjectName(QString::fromUtf8("label_Order"));

        gridLayout_3->addWidget(label_Order, 0, 1, 1, 1);

        tableView_Order = new QTableView(OrderForm);
        tableView_Order->setObjectName(QString::fromUtf8("tableView_Order"));

        gridLayout_3->addWidget(tableView_Order, 1, 0, 1, 2);

        groupBox_Add = new QGroupBox(OrderForm);
        groupBox_Add->setObjectName(QString::fromUtf8("groupBox_Add"));
        gridLayout = new QGridLayout(groupBox_Add);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spinBox_addAmount = new QSpinBox(groupBox_Add);
        spinBox_addAmount->setObjectName(QString::fromUtf8("spinBox_addAmount"));

        gridLayout->addWidget(spinBox_addAmount, 0, 4, 1, 1);

        label_addAmount = new QLabel(groupBox_Add);
        label_addAmount->setObjectName(QString::fromUtf8("label_addAmount"));

        gridLayout->addWidget(label_addAmount, 0, 3, 1, 1);

        comboBox_Plastic = new QComboBox(groupBox_Add);
        comboBox_Plastic->setObjectName(QString::fromUtf8("comboBox_Plastic"));

        gridLayout->addWidget(comboBox_Plastic, 1, 1, 1, 1);

        label_addName = new QLabel(groupBox_Add);
        label_addName->setObjectName(QString::fromUtf8("label_addName"));

        gridLayout->addWidget(label_addName, 0, 0, 1, 1);

        lineEdit_addName = new QLineEdit(groupBox_Add);
        lineEdit_addName->setObjectName(QString::fromUtf8("lineEdit_addName"));

        gridLayout->addWidget(lineEdit_addName, 0, 1, 1, 2);

        label_Plastic = new QLabel(groupBox_Add);
        label_Plastic->setObjectName(QString::fromUtf8("label_Plastic"));

        gridLayout->addWidget(label_Plastic, 1, 0, 1, 1);

        label_Weight = new QLabel(groupBox_Add);
        label_Weight->setObjectName(QString::fromUtf8("label_Weight"));

        gridLayout->addWidget(label_Weight, 1, 3, 1, 1);

        pushButton_addPrint = new QPushButton(groupBox_Add);
        pushButton_addPrint->setObjectName(QString::fromUtf8("pushButton_addPrint"));

        gridLayout->addWidget(pushButton_addPrint, 0, 9, 4, 1);

        doubleSpinBox_addWeight = new QDoubleSpinBox(groupBox_Add);
        doubleSpinBox_addWeight->setObjectName(QString::fromUtf8("doubleSpinBox_addWeight"));

        gridLayout->addWidget(doubleSpinBox_addWeight, 1, 4, 1, 1);

        label_Time = new QLabel(groupBox_Add);
        label_Time->setObjectName(QString::fromUtf8("label_Time"));

        gridLayout->addWidget(label_Time, 0, 5, 1, 2);

        doubleSpinBox_addTime = new QDoubleSpinBox(groupBox_Add);
        doubleSpinBox_addTime->setObjectName(QString::fromUtf8("doubleSpinBox_addTime"));

        gridLayout->addWidget(doubleSpinBox_addTime, 0, 7, 1, 1);

        doubleSpinBox_PremiumRate = new QDoubleSpinBox(groupBox_Add);
        doubleSpinBox_PremiumRate->setObjectName(QString::fromUtf8("doubleSpinBox_PremiumRate"));

        gridLayout->addWidget(doubleSpinBox_PremiumRate, 3, 4, 1, 1);

        label_PR = new QLabel(groupBox_Add);
        label_PR->setObjectName(QString::fromUtf8("label_PR"));

        gridLayout->addWidget(label_PR, 3, 0, 1, 4);

        checkBox_Done = new QCheckBox(groupBox_Add);
        checkBox_Done->setObjectName(QString::fromUtf8("checkBox_Done"));

        gridLayout->addWidget(checkBox_Done, 1, 5, 1, 1);

        checkBox_Defective = new QCheckBox(groupBox_Add);
        checkBox_Defective->setObjectName(QString::fromUtf8("checkBox_Defective"));

        gridLayout->addWidget(checkBox_Defective, 3, 5, 1, 1);


        gridLayout_3->addWidget(groupBox_Add, 2, 0, 1, 2);

        groupBox = new QGroupBox(OrderForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_ID = new QLabel(groupBox);
        label_ID->setObjectName(QString::fromUtf8("label_ID"));

        gridLayout_2->addWidget(label_ID, 0, 0, 1, 1);

        lineEdit_deleteID = new QLineEdit(groupBox);
        lineEdit_deleteID->setObjectName(QString::fromUtf8("lineEdit_deleteID"));

        gridLayout_2->addWidget(lineEdit_deleteID, 0, 1, 1, 1);

        pushButton_deletePrint = new QPushButton(groupBox);
        pushButton_deletePrint->setObjectName(QString::fromUtf8("pushButton_deletePrint"));

        gridLayout_2->addWidget(pushButton_deletePrint, 0, 2, 1, 1);


        gridLayout_3->addWidget(groupBox, 3, 0, 1, 2);

        groupBox_2 = new QGroupBox(OrderForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout_3->addWidget(groupBox_2, 4, 0, 1, 2);


        retranslateUi(OrderForm);

        QMetaObject::connectSlotsByName(OrderForm);
    } // setupUi

    void retranslateUi(QWidget *OrderForm)
    {
        OrderForm->setWindowTitle(QCoreApplication::translate("OrderForm", "Form", nullptr));
        toolButton_close->setText(QCoreApplication::translate("OrderForm", "X", nullptr));
        label_Order->setText(QString());
        groupBox_Add->setTitle(QCoreApplication::translate("OrderForm", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\265\321\207\320\260\321\202\320\270", nullptr));
        label_addAmount->setText(QCoreApplication::translate("OrderForm", "<html><head/><body><p align=\"right\">\320\232\320\276\320\273-\320\262\320\276 :</p></body></html>", nullptr));
        label_addName->setText(QCoreApplication::translate("OrderForm", "<html><head/><body><p align=\"right\">\320\230\320\274\321\217 :</p></body></html>", nullptr));
        label_Plastic->setText(QCoreApplication::translate("OrderForm", "<html><head/><body><p align=\"right\">\320\237\320\273\320\260\321\201\321\202\320\270\320\272 :</p></body></html>", nullptr));
        label_Weight->setText(QCoreApplication::translate("OrderForm", "<html><head/><body><p align=\"right\">\320\222\320\265\321\201 :</p></body></html>", nullptr));
        pushButton_addPrint->setText(QCoreApplication::translate("OrderForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\265\321\207\320\260\321\202\321\214", nullptr));
        label_Time->setText(QCoreApplication::translate("OrderForm", "<html><head/><body><p align=\"right\">\320\222\321\200\320\265\320\274\321\217 \320\277\320\265\321\207\320\260\321\202\320\270, \321\207 :</p></body></html>", nullptr));
        label_PR->setText(QCoreApplication::translate("OrderForm", "<html><head/><body><p align=\"right\">\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\275\320\260\320\264\320\261\320\260\320\262\320\276\321\207\320\275\320\276\320\271 \321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\320\270 :</p></body></html>", nullptr));
        checkBox_Done->setText(QCoreApplication::translate("OrderForm", "\320\241\320\264\320\265\320\273\320\260\320\275\320\260", nullptr));
        checkBox_Defective->setText(QCoreApplication::translate("OrderForm", "\320\221\321\200\320\260\320\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("OrderForm", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\277\320\265\321\207\320\260\321\202\320\270", nullptr));
        label_ID->setText(QCoreApplication::translate("OrderForm", "Id :", nullptr));
        pushButton_deletePrint->setText(QCoreApplication::translate("OrderForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\265\321\207\320\260\321\202\321\214", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("OrderForm", "\320\227\320\260\320\272\320\260\320\267", nullptr));
        pushButton->setText(QCoreApplication::translate("OrderForm", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("OrderForm", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265", nullptr));
        pushButton_2->setText(QCoreApplication::translate("OrderForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrderForm: public Ui_OrderForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERFORM_H
