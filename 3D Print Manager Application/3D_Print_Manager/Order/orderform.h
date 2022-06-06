#ifndef ORDERFORM_H
#define ORDERFORM_H

#include <QWidget>
#include <QtSql/QtSql>
#include <QList>

namespace Ui {
class OrderForm;
}

class OrderForm : public QWidget
{
    Q_OBJECT

public:
    explicit OrderForm(QWidget *parent = nullptr);
    ~OrderForm();
    void createOrderModel(const QSqlDatabase &db, const QString &orderid);
    void setlabel(QList<QString> params);

signals:
    void closeTab();

private slots:
    void on_toolButton_close_clicked();

private:
    Ui::OrderForm *ui;
    QSqlTableModel *model;
};

#endif // ORDERFORM_H
