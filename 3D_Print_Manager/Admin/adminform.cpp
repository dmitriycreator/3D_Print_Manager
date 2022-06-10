#include "adminform.h"
#include "ui_adminform.h"

AdminForm::AdminForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminForm)
{
    Paramsadded = false;
    Usersadded = false;
    Incomeadded = false;

    //ui_Users = new UsersForm;
    //ui_Params = new ParamsForm;
    //ui_Income = new IncomeForm;

    ui->setupUi(this);
}

AdminForm::~AdminForm()
{
    delete ui_Users;
    delete ui_Income;
    delete ui_Params;
    delete ui;
}

void AdminForm::on_pushButton_Users_clicked() // создания окна списка пользователей
{
    if(Usersadded) // если окно уже есть, то вернуться
        return;
    ui_Users = new UsersForm;

    connect(ui_Users, SIGNAL(addUser()), // соединение сигналов со слотами
            this, SLOT(addUser()));
    connect(ui_Users, SIGNAL(deleteUser()),
            this, SLOT(deleteUser()));
    connect(ui_Users, SIGNAL(closeUsersForm()),
            this, SLOT(closeUsersForm()));

    ui_Users->createUserTableModel(manager.db_manager.mw_db); // создаем модель таблицы окна
    ui->horizontalLayout->addWidget(ui_Users); // добавляем окно в layout
    Usersadded = true; // флаг добавленного окна
}


void AdminForm::on_pushButton_Income_clicked() // создание окна доходов
{
    if(Incomeadded)
        return;
    ui_Income = new IncomeForm;

    connect(ui_Income, SIGNAL(findAllIncome()),
            this, SLOT(findAllIncome()));
    connect(ui_Income, SIGNAL(closeIncomeForm()),
            this, SLOT(closeIncomeForm()));

    ui_Income->createTableModel(manager.db_manager.mw_db);
    ui->horizontalLayout->addWidget(ui_Income);
    Incomeadded = true;
}

void AdminForm::on_pushButton_Params_clicked() // создание окна параметров печати
{
    if(Paramsadded)
        return;
    ui_Params = new ParamsForm;

    connect(ui_Params, SIGNAL(addPlastic()),
            this, SLOT(addPlastic()));
    connect(ui_Params, SIGNAL(deletePlastic()),
            this, SLOT(deletePlastic()));
    connect(ui_Params, SIGNAL(closeParamsForm()),
            this, SLOT(closeParamsForm()));

    ui_Params->createParamsTableModel(manager.db_manager.mw_db);
    ui->horizontalLayout->addWidget(ui_Params);
    Paramsadded = true;
}

// Метод инициализации окна администратора базой данных
void AdminForm::initwithDB(const QString &DBFilePath)
{
    manager.initManagerWithDB(DBFilePath);
    ui->horizontalLayout->addWidget(&manager);
}

void AdminForm::addUser() // метод добавления нового пользователя
{
    UsersForm *form = (UsersForm*) sender();
    QList<QString> params = form->getUserParams();
    if(!manager.addUser(params))
         QMessageBox::critical(this, "Ошибка", "Пользователь с таким логином уже существует!");
}

void AdminForm::deleteUser() // метод удаления пользователя
{
    UsersForm *form = (UsersForm*) sender();
    QString username = form->getLogin();
    manager.deleteUser(username);
}

void AdminForm::findAllIncome() // метод нахождения общего дохода
{
    manager.findAllIncome();
}

void AdminForm::addPlastic() // метод добавления пластика
{
    ParamsForm *form = (ParamsForm*) sender();
    QString name = form->getName();
    QString cost = form->getCost();
    if(!manager.addPlastic(name, cost))
        QMessageBox::critical(this, "Ошибка", "Пластик уже существует!");
}

void AdminForm::deletePlastic() // метод удаления пластика
{
    ParamsForm *form = (ParamsForm*) sender();
    QString name = form->getDel();
    manager.delPlastic(name);
}

// Методы закрытия окон
void AdminForm::closeIncomeForm()
{
    IncomeForm *form = (IncomeForm*) sender(); // определяем объект, от которого пришел запрос
    ui->horizontalLayout->removeWidget(form); // убираем его из layout
    form->deleteLater(); // удаляем объект и обновляем layout
    ui->horizontalLayout->update();
    Incomeadded = false;
}

void AdminForm::closeParamsForm()
{
    ParamsForm *form = (ParamsForm*) sender();
    ui->horizontalLayout->removeWidget(form);
    form->deleteLater();
    ui->horizontalLayout->update();
    Paramsadded = false;
}

void AdminForm::closeUsersForm()
{
    UsersForm *form = (UsersForm*) sender();
    ui->horizontalLayout->removeWidget(form);
    form->deleteLater();
    ui->horizontalLayout->update();
    Usersadded = false;
}
