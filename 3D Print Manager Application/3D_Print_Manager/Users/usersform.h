#ifndef USERSFORM_H
#define USERSFORM_H

#include <QWidget>
#include <QtSql/QtSql>
#include <QMessageBox>

namespace Ui {
class UsersForm;
}

class UsersForm : public QWidget
{
    Q_OBJECT

public:
    explicit UsersForm(QWidget *parent = nullptr);
    ~UsersForm();
    QList<QString> getUserParams();
    QString getLogin();
    void createUserTableModel(const QSqlDatabase &db);

signals:
    void addUser();
    void deleteUser();
    void closeUsersForm();

private slots:
    void on_pushButton_addUser_clicked();

    void on_pushButton_delUser_clicked();

    void on_toolButton_close_clicked();

private:
    Ui::UsersForm *ui;
    QString username_del;
    QList<QString> add_params;
    QSqlTableModel *model;
};

#endif // USERSFORM_H
