#ifndef MANAGERTABWIDGET_H
#define MANAGERTABWIDGET_H

#include <QTabWidget>
#include <QMessageBox>
#include "Order/orderform.h"
#include "Orders/ordersform.h"
#include "Database/database.h"

namespace Ui {
class ManagerTabWidget;
}

class ManagerTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit ManagerTabWidget(QWidget *parent = nullptr);
    ~ManagerTabWidget();
    void initManagerWithDB(const QString &DBFilePath); // метод инициализации виджета менеджера базой данных

private slots:
    void createNewOrder(); // метод создания нового заказа
    void openOrder(); // метод открытия заказа

    void closeOrder(); // метод закрытия вкладки с заказом

private:
    Ui::ManagerTabWidget *ui;
    void createOrderTab(const QList<QString> &params); // метод создания вкладки заказа

    OrdersForm *ui_Orders; // форма списка заказов
    OrderForm *ui_Order; // формы заказов

    Database db_manager; // объект базы данных
};

#endif // MANAGERTABWIDGET_H
