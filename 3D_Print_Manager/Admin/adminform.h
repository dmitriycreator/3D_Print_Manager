#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QWidget>
#include "Manager/managertabwidget.h"
#include "Users/usersform.h"
#include "Income/incomeform.h"
#include "Params/paramsform.h"

namespace Ui {
class AdminForm;
}

class AdminForm : public QWidget
{
    Q_OBJECT

public:
    explicit AdminForm(QWidget *parent = nullptr);
    ~AdminForm();
    void initwithDB(const QString &DBFilePath); // метод инциализации окна базой данных

private slots:
    void on_pushButton_Users_clicked();

    void on_pushButton_Income_clicked();

    void on_pushButton_Params_clicked();

    void addUser(); // метод добавления пользователя
    void deleteUser(); // метод удаления пользователя

    void findAllIncome(); // метод нахождения общего дохода

    void deletePlastic(); // метод удаления пластика
    void addPlastic(); // метод добавления пластика

    void closeIncomeForm(); // метод закрытия окна доходов
    void closeParamsForm(); // метод закрытия окна параметров печати
    void closeUsersForm(); // метод закрытия окна списка пользователей

private:
    Ui::AdminForm *ui;
    ManagerTabWidget manager; // объект менеджера
    IncomeForm *ui_Income; // окно доходов
    UsersForm *ui_Users; // окно списка пользователей
    ParamsForm *ui_Params; // окно параметров печати

    bool Paramsadded; // флаги на добавленные окна
    bool Usersadded;
    bool Incomeadded;
};

#endif // ADMINFORM_H
