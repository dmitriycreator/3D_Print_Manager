#include "ordersform.h"
#include "ui_ordersform.h"

OrdersForm::OrdersForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrdersForm)
{
    ui->setupUi(this);
}

OrdersForm::~OrdersForm()
{
    delete ui;
}

// Метод создания модели таблицы заказов
void OrdersForm::createOrdersModel(const QSqlDatabase &db)
{
    model = new QSqlTableModel(this, db); // создание редактируемой модели БД

    model->setTable("orders"); // создание модели таблицы orders
    model->select();

    // Выбор стратегии сохранения изменений
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    ui->tableView_Orders->setModel(model); // соединение модели с таблицей

    model->setHeaderData(0, Qt::Horizontal, "Id");
    model->setHeaderData(1, Qt::Horizontal, "Имя");
    model->setHeaderData(2, Qt::Horizontal, "Дата");
}

void OrdersForm::on_pushButton_Open_clicked()
{
    emit tabopenOrder();
}


void OrdersForm::on_pushButton_Create_clicked()
{
    emit tabcreateNewOrder();
    model->select();
}


void OrdersForm::on_lineEdit_Open_textEdited(const QString &arg1)
{
    orderid = arg1;
}


void OrdersForm::on_lineEdit_Create_textEdited(const QString &arg1)
{
    ordername = arg1;
}

QString OrdersForm::getID()
{
    return orderid;
}

QString OrdersForm::getName()
{
    return ordername;
}
