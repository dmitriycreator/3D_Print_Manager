#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "Auth_Form/authform.h"
#include "Reg_Form/regform.h"
#include "Database/database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void display(); // пользовательская функция отображения

private slots:
    void authoriseUser(); // метод авторизации пользователя
    void registerUser(); // метод регистрации пользователя

    void registerFormShow(); // метод открытия окна регистрации
    void returnToAuthForm(); // метод возвращения к окну авторизации

private:
    Ui::MainWindow *ui;
    AuthForm ui_Auth; // окно авторизации
    RegForm ui_Reg; // окно регистрации

    QString m_username; // строки обработки
    QString m_userpass; // пользовательского ввода

    QString role; // роль пользователя

    Database data; // объект БД

    bool m_loginSuccesfull; // флаг успешной авторизации
};
#endif // MAINWINDOW_H
