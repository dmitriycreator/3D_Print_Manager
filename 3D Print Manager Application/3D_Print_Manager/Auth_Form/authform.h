#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>

namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();
    QString getLogin(); // метод получения логина
    QString getPass(); // метод получения пароля

signals:
    void login_button_clicked(); // нажатие кнопки Вход
    void register_button_clicked(); // нажатие кнопки Регистрация

private slots:
    void on_lineEdit_Login_textEdited(const QString &arg1);

    void on_lineEdit_Pass_textEdited(const QString &arg1);

    void on_pushButton_Log_clicked();

    void on_pushButton_Reg_clicked();

private:
    Ui::AuthForm *ui;

    QString username; // логин
    QString userpass; // пароль
};

#endif // AUTHFORM_H
