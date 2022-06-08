#ifndef ORDERSFORM_H
#define ORDERSFORM_H

#include <QWidget>
#include <QtSql/QtSql>

namespace Ui {
class OrdersForm;
}

class OrdersForm : public QWidget
{
    Q_OBJECT

public:
    explicit OrdersForm(QWidget *parent = nullptr);
    ~OrdersForm();
    void createOrdersModel(const QSqlDatabase &db); // метод создания модели таблицы заказов
    QString getID(); // метод получения id заказа
    QString getName(); // метод получения имени заказа
    void refresh(); // обновление таблицы

signals:
    void tabcreateNewOrder(); // нажатие кнопки создать заказ
    void tabopenOrder(); // нажатие кнопки открыть заказ

private slots:
    void on_pushButton_Open_clicked();

    void on_pushButton_Create_clicked();

    void on_lineEdit_Open_textEdited(const QString &arg1);

    void on_lineEdit_Create_textEdited(const QString &arg1);

private:
    Ui::OrdersForm *ui;
    QSqlTableModel *model; // модель таблицы заказов
    QString orderid; // id заказа
    QString ordername; // имя заказа
};

#endif // ORDERSFORM_H
