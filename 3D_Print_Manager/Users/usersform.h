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
    QList<QString> getUserParams(); // метод получения параметров нового пользователя
    QString getLogin(); // метод получения логина пользователя
    void createUserTableModel(const QSqlDatabase &db); // метод создания модели таблицы БД

signals:
    void addUser(); // сигнал добавления пользователя
    void deleteUser(); // сигнал удаления пользователя
    void closeUsersForm(); // сигнал закрытия окна списка пользователей

private slots:
    void on_pushButton_addUser_clicked();

    void on_pushButton_delUser_clicked();

    void on_toolButton_close_clicked();

private:
    Ui::UsersForm *ui;
    QString username_del; // логин пользователя на удаление
    QList<QString> add_params; // параметры нового пользователя
    QSqlTableModel *model; // объект модели БД
};

#endif // USERSFORM_H
