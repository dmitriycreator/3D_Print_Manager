#include "incomeform.h"
#include "ui_incomeform.h"

IncomeForm::IncomeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IncomeForm)
{
    ui->setupUi(this);
}

IncomeForm::~IncomeForm()
{
    delete model;
    delete ui;
}

// Метод создания модели таблицы из БД
void IncomeForm::createTableModel(const QSqlDatabase &db)
{
    model = new QSqlTableModel(this, db);
    model->setTable("income");
    model->select();

    model->setHeaderData(0, Qt::Horizontal, "Id");
    model->setHeaderData(1, Qt::Horizontal, "Дата");
    model->setHeaderData(2, Qt::Horizontal, "Доход");

    ui->tableView_Income->setModel(model);
}

void IncomeForm::on_pushButton_refresh_clicked()
{
    model->select();
}


void IncomeForm::on_pushButton_AllIncome_clicked()
{
    emit findAllIncome();
}


void IncomeForm::on_toolButton_close_clicked()
{
    emit closeIncomeForm();
}
