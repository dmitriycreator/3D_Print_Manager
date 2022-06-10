#include "regform.h"
#include "ui_regform.h"

RegForm::RegForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegForm)
{
    ui->setupUi(this);
}

RegForm::~RegForm()
{
    delete ui;
}

void RegForm::on_lineEdit_Name_textEdited(const QString &arg1)
{
    username = arg1;
}


void RegForm::on_lineEdit_Pass_textEdited(const QString &arg1)
{
    userpass = arg1;
}


void RegForm::on_lineEdit_Confirm_textEdited(const QString &arg1)
{
    confirmation = arg1;
}


void RegForm::on_pushButton_Create_clicked()
{
    emit create_button_clicked(); // сигнал нажатия кнопки Создать
}


void RegForm::on_pushButton_Back_clicked()
{
    emit back_button_clicked(); // сигнал нажатия кнопки Отмена
}

// Метод получения логина
QString RegForm::getLogin()
{
    return username;
}

// Метод получения пароля
QString RegForm::getPass()
{
    return userpass;
}

// Метод проверки подтверждения пароля
bool RegForm::checkPass()
{
    return (userpass == confirmation);
}
