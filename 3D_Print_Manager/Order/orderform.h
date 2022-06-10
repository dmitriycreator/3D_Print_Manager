#ifndef ORDERFORM_H
#define ORDERFORM_H

#include <QWidget>
#include <QtSql/QtSql>
#include <QList>
#include <QMessageBox>

namespace Ui {
class OrderForm;
}

class OrderForm : public QWidget
{
    Q_OBJECT

public:
    explicit OrderForm(QWidget *parent = nullptr);
    ~OrderForm();
    void createOrderModel(const QSqlDatabase &db, const QString &orderid); // метод создания модели таблицы заказов
    void setlabel(QList<QString> params); // метод установления пояснительной надписи заказа

    void connectComboBox(const QList<QString> &items); // метод установления пластиков в комбобокс выбора пластика

    QString getID(); // метод получения id заказа
    QList<QString> getPrintParams(); // метод получения параметров печати из формы
    QString getPrintId(); // метод получения id печати на удаление

signals:
    void closeTab(); // сигнал закрытия вкладки с заказом
    void addPrint(); // сигнал добавления новой печати
    void deletePrint(); // сигнал на удаление печати
    void findCost_button(); // сигнал на расчет стоимости заказа
    void finishOrder_clicked(); // сигнал завершения заказа
    void deleteOrder_clicked(); // сигнал удаления заказа

private slots:
    void on_toolButton_close_clicked();

    void on_pushButton_addPrint_clicked();

    void on_lineEdit_deleteID_textEdited(const QString &arg1);

    void on_pushButton_deletePrint_clicked();

    void chBox_defectiveChecked(bool isChecked); // щелчок по чекбоксу брак в таблице
    void chBox_doneChecked(bool isChecked); // щелчок по чекбоксу сделана в таблице

    void on_pushButton_findCost_clicked();

    void on_pushButton_finish_clicked();

    void on_pushButton_deleteOrder_clicked();

private:
    void setCheckBoxes(); // метод установления чекбоксов в таблицу

    Ui::OrderForm *ui;
    QSqlTableModel *model; // модель таблицы заказа

    QString m_orderid; // id заказа
    QList<QString> params; // параметры печати для отправки
    QString m_printid; // id печати для удаления
};

#endif // ORDERFORM_H
