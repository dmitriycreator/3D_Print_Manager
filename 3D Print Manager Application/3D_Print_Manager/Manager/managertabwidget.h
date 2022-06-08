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
    // Методы для админа
    bool addUser(const QList<QString> params);
    void deleteUser(const QString username);
    void findAllIncome();
    bool addPlastic(const QString &name, const QString &cost);
    void delPlastic(const QString &name);
    Database db_manager; // объект базы данных

private slots:
    void createNewOrder(); // метод создания нового заказа
    void openOrder(); // метод открытия заказа

    void closeOrder(); // метод закрытия вкладки с заказом
    void addPrint(); // метод добавления новой печати
    void deletePrint(); // метод удаления печати

    void findCost(); // метод расчета стоимости заказа
    void finishOrder(); // метод завершения заказа
    void deleteOrder(); // метод удаления заказа

private:
    Ui::ManagerTabWidget *ui;
    void createOrderTab(const QList<QString> &params); // метод создания вкладки заказа

    OrdersForm *ui_Orders; // форма списка заказов
    OrderForm *ui_Order; // формы заказов
};

#endif // MANAGERTABWIDGET_H
