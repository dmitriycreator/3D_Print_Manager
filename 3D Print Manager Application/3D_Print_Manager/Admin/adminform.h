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
    void initwithDB(const QString &DBFilePath); //

private slots:
    void on_pushButton_Users_clicked();

    void on_pushButton_Income_clicked();

    void addUser();
    void deleteUser();

    void findAllIncome();

    void deletePlastic();
    void addPlastic();

    void on_pushButton_Params_clicked();

    void closeIncomeForm();
    void closeParamsForm();
    void closeUsersForm();

private:
    Ui::AdminForm *ui;
    //Database db_admin;
    ManagerTabWidget manager;
    //QSqlDatabase db_admin;
    IncomeForm *ui_Income;
    UsersForm *ui_Users;
    ParamsForm *ui_Params;

    bool Paramsadded;
    bool Usersadded;
    bool Incomeadded;
};

#endif // ADMINFORM_H
