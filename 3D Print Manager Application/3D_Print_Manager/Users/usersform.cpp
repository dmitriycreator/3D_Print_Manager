#include "usersform.h"
#include "ui_usersform.h"

UsersForm::UsersForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UsersForm)
{
    ui->setupUi(this);
}

UsersForm::~UsersForm()
{
    delete model;
    delete ui;
}

QList<QString> UsersForm::getUserParams()
{
    return add_params;
}

QString UsersForm::getLogin()
{
    return username_del;
}

void UsersForm::on_pushButton_addUser_clicked()
{
    QString name = ui->lineEdit_Name->text();
    QString pass = ui->lineEdit_Pass->text();
    QString role = ui->lineEdit_Role->text();
    if(name.isEmpty() || pass.isEmpty() || role.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Поля не должны быть пустыми!");
        return;
    }
    add_params = {
        name,
        pass,
        role
    };
    emit addUser();
    model->select();
}


void UsersForm::on_pushButton_delUser_clicked()
{
    username_del = ui->lineEdit_delUser->text();
    if(username_del.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Поле логин не должно быть пустым!");
        return;
    }
    emit deleteUser();
    model->select();
}

void UsersForm::createUserTableModel(const QSqlDatabase &db)
{
    model = new QSqlTableModel(this, db);
    model->setTable("users");
    model->select();

    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->setHeaderData(0, Qt::Horizontal, "Id");
    model->setHeaderData(1, Qt::Horizontal, "Имя");
    model->setHeaderData(3, Qt::Horizontal, "Роль");

    ui->tableView_Users->setModel(model);
    ui->tableView_Users->hideColumn(2);
}

void UsersForm::on_toolButton_close_clicked()
{
    emit closeUsersForm();
}

