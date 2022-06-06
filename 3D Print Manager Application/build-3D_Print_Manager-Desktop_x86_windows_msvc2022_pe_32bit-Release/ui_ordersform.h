/********************************************************************************
** Form generated from reading UI file 'ordersform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERSFORM_H
#define UI_ORDERSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrdersForm
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_DB;
    QTableView *tableView_Orders;
    QGroupBox *groupBox_Orders;
    QGridLayout *gridLayout;
    QLabel *label_Name;
    QLabel *label_ID;
    QLineEdit *lineEdit_Open;
    QPushButton *pushButton_Open;
    QLineEdit *lineEdit_Create;
    QPushButton *pushButton_Create;
    QFrame *line;

    void setupUi(QWidget *OrdersForm)
    {
        if (OrdersForm->objectName().isEmpty())
            OrdersForm->setObjectName(QString::fromUtf8("OrdersForm"));
        OrdersForm->resize(716, 657);
        gridLayout_2 = new QGridLayout(OrdersForm);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_DB = new QLabel(OrdersForm);
        label_DB->setObjectName(QString::fromUtf8("label_DB"));

        gridLayout_2->addWidget(label_DB, 0, 0, 1, 2);

        tableView_Orders = new QTableView(OrdersForm);
        tableView_Orders->setObjectName(QString::fromUtf8("tableView_Orders"));

        gridLayout_2->addWidget(tableView_Orders, 1, 0, 1, 1);

        groupBox_Orders = new QGroupBox(OrdersForm);
        groupBox_Orders->setObjectName(QString::fromUtf8("groupBox_Orders"));
        gridLayout = new QGridLayout(groupBox_Orders);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_Name = new QLabel(groupBox_Orders);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));

        gridLayout->addWidget(label_Name, 3, 0, 1, 1);

        label_ID = new QLabel(groupBox_Orders);
        label_ID->setObjectName(QString::fromUtf8("label_ID"));

        gridLayout->addWidget(label_ID, 0, 0, 1, 1);

        lineEdit_Open = new QLineEdit(groupBox_Orders);
        lineEdit_Open->setObjectName(QString::fromUtf8("lineEdit_Open"));

        gridLayout->addWidget(lineEdit_Open, 0, 1, 1, 1);

        pushButton_Open = new QPushButton(groupBox_Orders);
        pushButton_Open->setObjectName(QString::fromUtf8("pushButton_Open"));

        gridLayout->addWidget(pushButton_Open, 1, 0, 1, 2);

        lineEdit_Create = new QLineEdit(groupBox_Orders);
        lineEdit_Create->setObjectName(QString::fromUtf8("lineEdit_Create"));

        gridLayout->addWidget(lineEdit_Create, 3, 1, 1, 1);

        pushButton_Create = new QPushButton(groupBox_Orders);
        pushButton_Create->setObjectName(QString::fromUtf8("pushButton_Create"));

        gridLayout->addWidget(pushButton_Create, 4, 0, 1, 2);

        line = new QFrame(groupBox_Orders);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 1, 2);


        gridLayout_2->addWidget(groupBox_Orders, 1, 1, 1, 1);


        retranslateUi(OrdersForm);

        QMetaObject::connectSlotsByName(OrdersForm);
    } // setupUi

    void retranslateUi(QWidget *OrdersForm)
    {
        OrdersForm->setWindowTitle(QCoreApplication::translate("OrdersForm", "Form", nullptr));
        label_DB->setText(QString());
        groupBox_Orders->setTitle(QCoreApplication::translate("OrdersForm", "\320\227\320\260\320\272\320\260\320\267\321\213", nullptr));
        label_Name->setText(QCoreApplication::translate("OrdersForm", "<html><head/><body><p>\320\230\320\274\321\217 :</p></body></html>", nullptr));
        label_ID->setText(QCoreApplication::translate("OrdersForm", "Id :", nullptr));
        pushButton_Open->setText(QCoreApplication::translate("OrdersForm", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        pushButton_Create->setText(QCoreApplication::translate("OrdersForm", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrdersForm: public Ui_OrdersForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERSFORM_H
