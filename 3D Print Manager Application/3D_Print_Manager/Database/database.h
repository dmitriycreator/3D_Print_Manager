#ifndef DATABASE_H
#define DATABASE_H

#define USERSDB "Users.db"
#define KG 1000

#include <QtSql/QtSql>
#include <QList>
#include <QMap>
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
    void addPrint(const QString &orderid, const QList<QString> params); // метод добавления новой печати в заказ
    void deletePrint(const QString &orderid, const QString &printid); // метод удаления печати из заказа

    // Метод расчета стоимости заказа
    double findCost(const QString &orderid);
    // Метод расчета дохода заказа
    double findIncome(const QString &orderid);
    // Метод расчета убытков заказа
    double findConsumtion(const QString &orderid);
    void deleteOrder(const QString &orderid); // метод удаления таблицы заказа из БД

    double findAllIncome();

    // Метод добавления дохода в таблицу
    void addIncome(const QString &orderid, const double &income);

    // Методы работы с параметрами печати
    void addPlastic(const QString &plastic, const double &cost); // метод добавления нового пластика
    void deletePlastic(const QString &plastic); // метод удаления пластика
    bool findPlastic(const QString &plastic); // метод поиска пластика по имени
    QMap<QString, double> getPlastics(); // метод получения списка пластиков
    QList<QString> getPlasticNames(); // метод получения списка названий пластиков
    void initTestPrintParams(); // установить тестовые параметры печати

    QSqlDatabase mw_db; // объект базы данных

private:
    QSqlQuery *query; // указатель на запрос
    QSqlRecord rec; // текущая запись

    QString get_hash(const QString &str); // получение хеш-кода в формате Md5
};

#endif // DATABASE_H
