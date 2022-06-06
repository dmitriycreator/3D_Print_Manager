#ifndef DATABASE_H
#define DATABASE_H

#define USERSDB "Users.db"

#include <QtSql/QtSql>
#include <QList>
#include <QCryptographicHash>
#include <QDate>

class Database
{
public:
    explicit Database();
    ~Database();

    void connectToDatabase(const QString &dbName = QString("db")); // метод подключения к БД
    void connectToUsersDB(); // метод подключения к БД пользователей
    QList<QString> createNewOrder(const QString &ordername); // метод создания нового заказа
    //void createNewOrder(const QString &ordername); // метод создания нового заказа

    // Методы работы с таблицей пользователей
    void addUser(const QList<QString> params); // метод добавления нового пользователя
    void deleteUser(const QString &username); // метод удаления пользователя
    bool searchUser(const QString &username); // метод поиска пользователя в БД
    bool checkLogData(const QString &username, const QString &userpass); // метод проверки входа в учетную запись
    QList<QString> getUserParams(const QString &username); // метод получения данных пользователя

    // Методы работы с заказом
    QList<QString> getOrderParams(const QString &orderid); // метод получения данных о заказе из БД

    QSqlDatabase mw_db; // объект базы данных

private:
    QSqlQuery *query; // указатель на запрос
    QSqlRecord rec; // текущая запись

    QString get_hash(const QString &str); // получение хеш-кода в формате Md5
};

#endif // DATABASE_H
