#include "paramsform.h"
#include "ui_paramsform.h"

ParamsForm::ParamsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParamsForm)
{
    ui->setupUi(this);
}

ParamsForm::~ParamsForm()
{
    delete model;
    delete ui;
}

void ParamsForm::createParamsTableModel(const QSqlDatabase &db)
{
    model = new QSqlTableModel(this, db);
    model->setTable("params");
    model->select();

    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->setHeaderData(0, Qt::Horizontal, "Имя");
    model->setHeaderData(1, Qt::Horizontal, "Цена за г");

    ui->tableView_Params->setModel(model);
}

void ParamsForm::on_pushButton_AddPlastic_clicked()
{
    if(plastic_name.isEmpty() || plastic_cost.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Поля не должны быть пустыми!");
        return;
    }
    emit addPlastic();
    model->select();
}


void ParamsForm::on_pushButton_delPlastic_clicked()
{
    if(del_plastic.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Поле имя не должно быть пустым!");
        return;
    }
    emit deletePlastic();
    model->select();
}


void ParamsForm::on_lineEdit_Name_textEdited(const QString &arg1)
{
    plastic_name = arg1;
}


void ParamsForm::on_lineEdit_Cost_textEdited(const QString &arg1)
{
    plastic_cost = arg1;
}


void ParamsForm::on_lineEdit_Del_textEdited(const QString &arg1)
{
    del_plastic = arg1;
}

QString ParamsForm::getCost()
{
    return plastic_cost;
}

QString ParamsForm::getName()
{
    return plastic_name;
}

QString ParamsForm::getDel()
{
    return del_plastic;
}

void ParamsForm::on_toolButton_close_clicked()
{
    emit closeParamsForm();
}

