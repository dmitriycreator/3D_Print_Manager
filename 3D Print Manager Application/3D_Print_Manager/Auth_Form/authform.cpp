#include "authform.h"
#include "ui_authform.h"

AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    ui->setupUi(this);
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::on_lineEdit_Login_textEdited(const QString &arg1)
{
    username = arg1;
}


void AuthForm::on_lineEdit_Pass_textEdited(const QString &arg1)
{
    userpass = arg1;
}


void AuthForm::on_pushButton_Log_clicked()
{
    emit login_button_clicked();
}


void AuthForm::on_pushButton_Reg_clicked()
{
    emit register_button_clicked();
}

QString AuthForm::getLogin()
{
    return username;
}

QString AuthForm::getPass()
{
    return userpass;
}
