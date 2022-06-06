#include "database.h"

Database::Database()
{
}

Database::~Database()
{
    delete query;
}

// Метод для создания новой базы данных или открытия существующей:
void Database::connectToDatabase(const QString &dbName)
{
   mw_db = QSqlDatabase::addDatabase("QSQLITE"); // соединение объекта БД с СУБД
   mw_db.setDatabaseName(dbName); // определение имени БД
   if(!mw_db.open()) // проверка на ошибку при открытии БД
   {
       qDebug() << "Unable to open DB: " << mw_db.lastError();
       throw "Unable to open DB!";
   }
   query = new QSqlQuery(mw_db); // создание объекта для запроса
   // Проверяем наличие таблиц в БД
   // Таблица пользователей:
   if(!mw_db.tables().contains("users")) // таблица пользователей
   {
       qDebug() << "Table 'users' doesn't exist";

       query->clear(); // очистка запроса

       qDebug() << "Creating table 'users':" <<
       query->exec("CREATE TABLE users("
                   " id INTEGER PRIMARY KEY NOT NULL, /* идентификатор */"
                   " login TEXT,                      /* логин */"
                   " password TEXT,                   /* пароль */"
                   " role TEXT                        /* роль */"
                   ");");
   }
   else qDebug() << "table 'users' exists";
   // Таблица заказов
   if(!mw_db.tables().contains("orders"))
   {
       qDebug() << "Table 'orders' doesn't exist";

       query->clear();

       qDebug() << "Creating table 'orders':" <<
       query->exec("CREATE TABLE orders("
                   " id INTEGER PRIMARY KEY NOT NULL, /* идентификатор */"
                   " name TEXT,                       /* имя */"
                   " date TEXT                        /* дата */"
                   ");");
   }
   else qDebug() << "Table 'orders' exists";
   // Таблица параметров печати
   if(!mw_db.tables().contains("params"))
   {
       qDebug() << "Table 'params' doesn't exist";

       query->clear();

       qDebug() << "Creating table 'params':" <<
       query->exec("CREATE TABLE params("
                   " id INTEGER PRIMARY KEY NOT NULL, /* идентификатор */"
                   " plastic TEXT,                    /* пластик */"
                   " cost INTEGER                     /* стоимость */"
                   ");");
   }
   else qDebug() << "Table 'params' exists";
}

//------------------------------Методы_ORDERS------------------------------//

// Метод создания нового заказа в базе данных
QList<QString> Database::createNewOrder(const QString &ordername)
{
    query->clear();
    query->prepare("SELECT MAX(e.id) AS 'number_of_orders' FROM orders AS 'e'");
    query->exec();
    if(!query->isActive())
        qDebug() << "Database Error: " << query->lastError();
    query->next();
    QString id = QString::number(query->value(0).toInt() + 1); // id нового заказа
    QString date = QDate::currentDate().toString(); // дата создания заказа

    query->clear();

    // Добавляем заказ в таблицу заказов
    qDebug() << "Adding new order " <<
    query->prepare("INSERT INTO orders(id, name, date) "
                   "VALUES(:id, :name, :date)");
    query->bindValue(":id", id);
    query->bindValue(":name", ordername);
    query->bindValue(":date", date);
    query->exec();

    // Создаем новую таблицу в базе данных
    query->clear();
    qDebug() << "Creating new order " << id << ", name " << ordername <<
    query->exec(QString("CREATE TABLE '%1' ("
                        " id INTEGER PRIMARY KEY NOT NULL, /* идентификатор */"
                        " name TEXT,                       /* имя */"
                        " amount INTEGER,                  /* количество */"
                        " weight DOUBLE,                   /* вес */"
                        " time DOUBLE,                     /* время */"
                        " plastic TEXT,                    /* пластик */"
                        " defective BOOL,                  /* брак */"
                        " done BOOL,                       /* сделана */"
                        " primaryrate DOUBLE               /* коэф_надбавки */"
                        ");").arg(id));

    QList<QString> params;
    params.append(id);
    params.append(ordername);
    params.append(date);

    return params;
}

// Метод получения параметров заказа из БД
QList<QString> Database::getOrderParams(const QString &orderid)
{
    query->clear();
    query->prepare(QString("SELECT * FROM orders WHERE id = :id"));
    query->bindValue(":id", orderid);
    query->exec();

    rec = query->record();
    query->next();

    QList<QString> params;
    params.append(query->value(rec.indexOf("id")).toString());
    params.append(query->value(rec.indexOf("name")).toString());
    params.append(query->value(rec.indexOf("date")).toString());
    return params;
}

//------------------------------Методы_USERS------------------------------//

// Метод на добавление нового пользователя
void Database::addUser(const QList<QString> params)
{
    /* Параметры:
     * params[0] - логин
     * params[1] - пароль
     * params[2] - роль */
    query->clear();
    query->prepare("SELECT MAX(e.id) AS 'number_of_users' FROM users AS 'e'");
    query->exec();
    if(!query->isActive())
        qDebug() << "Database Error: " << query->lastError();
    query->next();
    QString id = QString::number(query->value(0).toInt() + 1);
    QString hash_userpass = get_hash(params[1]);

    query->clear();

    qDebug() << "Adding new user " <<
    query->prepare("INSERT INTO users(id, login, password, role) "
                   "VALUES(:id, :login, :password, :role)");
    query->bindValue(":id", id);
    query->bindValue(":login", params[0]);
    query->bindValue(":password", hash_userpass);
    query->bindValue(":role", params[2]);
    query->exec();
}

// Метод удаления пользователя
void Database::deleteUser(const QString &username)
{
    query->clear();

    qDebug() << "deleting user " << username << " " <<
    query->exec(QString("DELETE FROM users WHERE login = '%1';").arg(username));
}

// Метод поиска пользотвателя по логину
bool Database::searchUser(const QString &username)
{
    query->clear();
    query->prepare("SELECT * FROM users WHERE login = :login");
    query->bindValue(":login", username);
    query->exec();

    rec = query->record();
    query->next();
    QString m_username = query->value(rec.indexOf("login")).toString();
    return (m_username == username);
}

// Метод проверки входа в учетную запись
bool Database::checkLogData(const QString &username, const QString &userpass)
{
    query->clear();
    query->prepare("SELECT * FROM users WHERE login = :login");
    query->bindValue(":login", username);
    query->exec();

    rec = query->record();
    query->next();
    QString m_username = query->value(rec.indexOf("login")).toString();
    QString m_userpass = query->value(rec.indexOf("password")).toString();
    QString hash_userpass = get_hash(userpass);
    return (m_username == username && m_userpass == hash_userpass);
}

// Метод получения данных пользователя
QList<QString> Database::getUserParams(const QString &username)
{
    query->clear();
    query->prepare("SELECT * FROM users WHERE login = :login");
    query->bindValue(":login", username);
    query->exec();

    rec = query->record();
    query->next();
    QList<QString> params;
    /* Параметры:
     * params[0] - id
     * params[1] - логин
     * params[2] - роль */
    params.append(query->value(rec.indexOf("id")).toString());
    params.append(query->value(rec.indexOf("login")).toString());
    params.append(query->value(rec.indexOf("role")).toString());
    return params;
}

// Метод получения хеш-кода в формате Md5
QString Database::get_hash(const QString &str)
{
    QByteArray arr = str.toUtf8();
    return QCryptographicHash::hash(arr, QCryptographicHash::Md5).toHex();
}
