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

QList<QString> UsersForm::getUserParams() // метод получения параметров нового пользователя
{
    return add_params;
}

QString UsersForm::getLogin() // метод получения логина пользователя
{
    return username_del;
}

void UsersForm::on_pushButton_addUser_clicked()
{
    QString name = ui->lineEdit_Name->text(); // получаем параметры пользователя в переменные
    QString pass = ui->lineEdit_Pass->text();
    QString role = ui->lineEdit_Role->text();
    if(name.isEmpty() || pass.isEmpty() || role.isEmpty()) // проверка на пустые поля
    {
        QMessageBox::warning(this, "Ошибка", "Поля не должны быть пустыми!");
        return;
    }
    add_params = { // создаем параметры
        name,
        pass,
        role
    };
    emit addUser(); // добавляем пользователя и обновляем таблицу
    model->select();
}


void UsersForm::on_pushButton_delUser_clicked()
{
    username_del = ui->lineEdit_delUser->text(); // получаем логин удаляемого пользователя
    if(username_del.isEmpty()) // проверка на пустое поле
    {
        QMessageBox::warning(this, "Ошибка", "Поле логин не должно быть пустым!");
        return;
    }
    emit deleteUser(); // удаляем и обновляем таблицу
    model->select();
}


// Метод создания модели таблицы пользователей
void UsersForm::createUserTableModel(const QSqlDatabase &db)
{
    model = new QSqlTableModel(this, db);
    model->setTable("users");
    model->select();

    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->setHeaderData(0, Qt::Horizontal, "Id"); // заголовки
    model->setHeaderData(1, Qt::Horizontal, "Имя");
    model->setHeaderData(3, Qt::Horizontal, "Роль");

    ui->tableView_Users->setModel(model);
    ui->tableView_Users->hideColumn(2); // прячем колонку с паролем
}

void UsersForm::on_toolButton_close_clicked()
{
    emit closeUsersForm();
}

