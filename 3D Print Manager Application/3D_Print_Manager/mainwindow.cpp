#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString MainWindow::fileDialogFilterString = tr("SQLite Database Files (*.sqlite3 *.sqlite *.db *.db3 *.sl3 *.s3db *.sdb *.sqlite2 *.db2 *.sl2 *.s2db)");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    m_loginSuccesfull = false;
    connect(&ui_Auth, SIGNAL(login_button_clicked()),
            this, SLOT(authoriseUser()));
    connect(&ui_Auth, SIGNAL(destroyed()),
            this, SLOT(show()));
    connect(&ui_Auth,SIGNAL(register_button_clicked()),
            this,SLOT(registerFormShow()));
    connect(&ui_Reg,SIGNAL(create_button_clicked()),
            this,SLOT(registerUser()));
    connect(&ui_Reg,SIGNAL(destroyed()),
            &ui_Auth, SLOT(show()));
    connect(&ui_Reg,SIGNAL(back_button_clicked()),
            this, SLOT(returnToAuthForm()));

    data.connectToUsersDB(); // подключение к базе пользователей

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow destroyed";
    delete ui;
}

// Пользовательский метод отображения
void MainWindow::display()
{
    ui_Auth.show();
}

// Метод переключения на форму регистрации
void MainWindow::registerFormShow()
{
    ui_Auth.hide();
    ui_Reg.show();
}

// Метод выхода из формы регистрации
void MainWindow::returnToAuthForm()
{
    ui_Reg.hide();
    ui_Auth.show();
}

// Метод авторизации пользователя
void MainWindow::authoriseUser()
{
    // Получаем логин и пароль с формы авторизации
    m_username = ui_Auth.getLogin();
    m_userpass = ui_Auth.getPass();

    // Проверка на пустые поля
    if(m_username.isEmpty() || m_userpass.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Поля не должны быть пустыми!");
        return;
    }
    // Проверяем данные в БД
    if(!data.checkLogData(m_username, m_userpass))
    {
        QMessageBox::warning(this, "Ошибка", "Пароль или логин неверны");
        return;
    }
    // Флаг успешной аавторизации
    m_loginSuccesfull = true;

    // Получаем данные о пользователе
    QList<QString> params = data.getUserParams(m_username);
    role = params[2];
    QString hi = "Добро пожаловать, '%1'";
    QMessageBox::information(this, "Здравствуйте", hi.arg(m_username));
    ui_Auth.close();
    ui_Reg.close();
    this->show();
}

// Метод регистрации пользователя
void MainWindow::registerUser()
{
    // Получаем пароль и логин
    m_username = ui_Reg.getLogin();
    m_userpass = ui_Reg.getPass();

    // Проверка на пустые поля
    if(m_username.isEmpty() || m_userpass.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Поля не должны быть пустыми!");
        return;
    }

    if(ui_Reg.checkPass()) // проверка подтверждения пароля
    {
        // Проверка уникальности логина
        if(data.searchUser(m_username))
        {
            QMessageBox::warning(this, "Ошибка", "Пользователь с таким логином уже существует!");
        }
        else
        {
            // Составляем параметры для создания пользователя
            /* Параметры
             * params[0] - логин
             * params[1] - пароль
             * params[2] - роль */
            QList<QString> params = {
              m_username,
              m_userpass,
              "manager"
            };
            data.addUser(params); // добавление пользователя в БД
            ui_Reg.hide(); // скрываем форму регистрации
            ui_Auth.show();
        }
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Пароль не подтвержден!");
    }
}

void MainWindow::on_action_createDB_triggered()
{
    QString dbFileFullPath = QFileDialog::getSaveFileName(this, "Создать базу данных Sql", "", MainWindow::fileDialogFilterString);
    data.connectToDatabase(dbFileFullPath);
}


void MainWindow::on_action_openDB_triggered()
{
    QString dbFileFullPath = QFileDialog::getOpenFileName(this, "Открыть базу данных Sql", "", MainWindow::fileDialogFilterString);
    data.connectToDatabase(dbFileFullPath);
}

