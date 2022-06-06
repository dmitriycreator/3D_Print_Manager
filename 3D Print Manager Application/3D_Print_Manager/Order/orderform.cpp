#include "orderform.h"
#include "ui_orderform.h"

OrderForm::OrderForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderForm)
{
    ui->setupUi(this);
}

OrderForm::~OrderForm()
{
    delete ui;
}

void OrderForm::createOrderModel(const QSqlDatabase &db, const QString &orderid)
{
    model = new QSqlTableModel(this, db);

    model->setTable(orderid);
    model->select();

    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    ui->tableView_Order->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "Id");
    model->setHeaderData(1, Qt::Horizontal, "Имя");
    model->setHeaderData(2, Qt::Horizontal, "Кол-во");
    model->setHeaderData(3, Qt::Horizontal, "Вес");
    model->setHeaderData(4, Qt::Horizontal, "Время печати");
    model->setHeaderData(5, Qt::Horizontal, "Пластик");
    model->setHeaderData(6, Qt::Horizontal, "Брак");
    model->setHeaderData(7, Qt::Horizontal, "Сделана");
    model->setHeaderData(8, Qt::Horizontal, "Коэф. надбавки");
}

void OrderForm::on_toolButton_close_clicked()
{
    emit closeTab();
}

void OrderForm::setlabel(QList<QString> params)
{
    ui->label_Order->setText(QString("Заказ id: %1  имя: %2  дата создания: %3").arg(params[0], params[1], params[2]));
}
