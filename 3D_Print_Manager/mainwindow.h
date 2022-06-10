#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include "Auth_Form/authform.h"
#include "Reg_Form/regform.h"
#include "Database/database.h"
#include "Manager/managertabwidget.h"
#include "Admin/adminform.h"
#include "help.h"

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

    void on_action_createDB_triggered(); // слот создания БД

    void on_action_openDB_triggered(); // слот открытия БД

    void on_action_Help_triggered();

private:
    Ui::MainWindow *ui;

    static const QString fileDialogFilterString; // варианты формата баз данных для диалога

    // Метод инициализации пользовательского интерфейса
    void initApp(const QString &dbFileFullPath); // передается путь к БД

    Help help; // окно помощи

    AuthForm ui_Auth; // окно авторизации
    RegForm ui_Reg; // окно регистрации
    ManagerTabWidget *manager; // указатель на виджет менеджера
    AdminForm *admin; // указатель на виджет админа

    QString m_username; // строки обработки
    QString m_userpass; // пользовательского ввода
    QString dbFileFullPath; // полный путь к базе данных

    QString role; // роль пользователя
    QString getRole; // полученная роль пользователя

    Database data; // объект БД

    bool m_loginSuccesfull; // флаг успешной авторизации
};
#endif // MAINWINDOW_H
