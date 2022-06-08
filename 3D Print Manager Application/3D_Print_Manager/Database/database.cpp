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
                   " plastic TEXT,                    /* пластик */"
                   " cost DOUBLE                     /* стоимость */"
                   ");");
   }
   else qDebug() << "Table 'params' exists";
   // Таблица доходов
   if(!mw_db.tables().contains("income"))
   {
       qDebug() << "Table 'income' doesn't exist";

       query->clear();

       qDebug() << "Creating table 'income':" <<
       query->exec("CREATE TABLE income("
                   " id INTEGER PRIMARY KEY NOT NULL, /* id_заказа */"
                   " date TEXT,                       /* дата_завершения */"
                   " income DOUBLE                    /* доход */"
                   ");");
   }
   else qDebug() << "Table 'income' exists";

   //initTestPrintParams();
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
                        " defective TEXT,                  /* брак */"
                        " done TEXT,                       /* сделана */"
                        " primaryrate DOUBLE               /* коэф_надбавки */"
                        ");").arg(id));

    // Создаем возвращаемые параметры
    /* Параметры
     * params[0] - id
     * params[1] - имя
     * params[2] дата создания */
    QList<QString> params;
    params.append(id);
    params.append(ordername);
    params.append(date);

    return params;
}

// Метод добавления новой печати в заказ
void Database::addPrint(const QString &orderid, const QList<QString> params)
{
    query->clear();
    query->prepare(QString("SELECT MAX(e.id) AS 'number_of_prints' FROM '%1' AS 'e'").arg(orderid));
    query->exec();
    if(!query->isActive())
        qDebug() << "Database Error: " << query->lastError();
    query->next();
    QString id = QString::number(query->value(0).toInt() + 1); // id новой печати

    query->clear();

    /* Параметры
     * params[0] - имя
     * params[1] - кол-во
     * params[2] - вес
     * params[3] - время печати
     * params[4] - пластик
     * params[5] - брак
     * params[6] - сделана
     * params[7] - коэффициент надбавки */
    // Добавляем печать в заказ
    qDebug() << "adding Print to order " << orderid << " " <<
    query->prepare(QString("INSERT INTO '%1'(id, name, amount, weight, time, plastic, defective, done, primaryrate) "
                   "VALUES(:id, :name, :amount, :weight, :time, :plastic, :defective, :done, :primaryrate)").arg(orderid));
    query->bindValue(":id", id);
    query->bindValue(":name", params[0]);
    query->bindValue(":amount", params[1]);
    query->bindValue(":weight", params[2]);
    query->bindValue(":time", params[3]);
    query->bindValue(":plastic", params[4]);
    query->bindValue(":defective", params[5]);
    query->bindValue(":done", params[6]);
    query->bindValue(":primaryrate", params[7]);
    query->exec();
}

// Метод удаления печати из заказа
void Database::deletePrint(const QString &orderid, const QString &printid)
{
    query->clear();

    qDebug() << "deleting print " << printid << " from order " << orderid <<
    query->exec(QString("DELETE FROM '%1' WHERE id = '%2';").arg(orderid, printid));
}

// Метод расчета стоимости заказа
double Database::findCost(const QString &orderid)
{
    QMap<QString, double> plastics = getPlastics(); // получаем пластики
    QMap<QString, double>::Iterator it; // итератор поиска по словарю
    double cost = 0; // стоимость заказа
    double plastic_cost; // стоимость пластика
    double primary_rate; // коэффициент надбавки
    double weight; // вес печати
    int amount; // кол-во печатей

    query->clear();

    qDebug() << "opening order " << orderid << " for Cost " <<
    query->exec(QString("SELECT amount, weight, plastic, done, primaryrate FROM '%1'").arg(orderid));

    /* Параметры
     * value(0) - id
     * value(1) - name
     * value(2) - amount
     * value(3) - weight
     * value(4) - time
     * value(5) - plastic
     * value(6) - defective
     * value(7) - done
     * value(8) - primary_rate */
    while(query->next())
    {
        qDebug() << query->value(3).toString();
        if(query->value(3).toString() == "да")
        {
            it = plastics.find(query->value(2).toString());
            plastic_cost = it.value();
            amount = query->value(0).toInt();
            weight = query->value(1).toDouble();
            primary_rate = query->value(4).toDouble();
            qDebug() << plastic_cost << " * " << weight << " * " << primary_rate << " * " << amount;
            cost += amount * weight * plastic_cost * primary_rate * KG; // добавляем стоимость детали к стоимости заказа
        }
    }

    return cost;
}

// Метод завершения заказа
double Database::findIncome(const QString &orderid)
{
    QMap<QString, double> plastics = getPlastics(); // получаем пластики
    QMap<QString, double>::Iterator it; // итератор поиска по словарю
    double income = 0; // переменная дохода
    double plastic_cost; // стоимость пластика
    double primary_rate; // коэффициент надбавки
    double weight; // вес печати
    int amount; // кол-во печатей

    query->clear();

    qDebug() << "opening order " << orderid << " for Income " <<
    query->exec(QString("SELECT amount, weight, plastic, defective, done, primaryrate FROM '%1'").arg(orderid));

    while(query->next())
    {
        qDebug() << query->value(4).toString();
        if(query->value(4).toString() == "да")
        {
            it = plastics.find(query->value(2).toString());
            plastic_cost = it.value();
            amount = query->value(0).toInt();
            weight = query->value(1).toDouble();
            primary_rate = query->value(5).toDouble();
            qDebug() << plastic_cost << " * " << weight << " * " << primary_rate << " * " << amount;
            if(query->value(3).toString() == "да")
                income -= amount * weight * plastic_cost * KG; // удаляем стоимость брака из дохода
            else income += amount * weight * plastic_cost * primary_rate * KG; // добавляем стоимость детали к доходу
        }
    }

    addIncome(orderid, income); // делаем запись в таблице доходов

    return income;
}

// Метод удаления заказа
double Database::findConsumtion(const QString &orderid)
{
    QMap<QString, double> plastics = getPlastics(); // получаем пластики
    QMap<QString, double>::Iterator it; // итератор поиска по словарю
    double consumption = 0; // переменная расхода
    double plastic_cost; // стоимость пластика
    double weight; // вес печати
    int amount; // кол-во печатей

    query->clear();

    qDebug() << "opening order " << orderid << " for Consumtion " <<
    query->exec(QString("SELECT amount, weight, plastic, defective, done FROM '%1'").arg(orderid));

    while(query->next())
    {
        qDebug() << query->value(4).toString();
        if(query->value(4).toString() == "да")
        {
            it = plastics.find(query->value(2).toString());
            plastic_cost = it.value();
            amount = query->value(0).toInt();
            weight = query->value(1).toDouble();
            qDebug() << plastic_cost << " * " << weight << " * " << " * " << amount;
            consumption -= amount * weight * plastic_cost * KG; // удаляем стоимость брака из дохода
        }
    }

    addIncome(orderid, consumption); // делаем запись в таблице доходов

    return consumption;
}

// Метод добавления дохода в таблицу
void Database::addIncome(const QString &orderid, const double &income)
{
    QString current_date = QDate::currentDate().toString();
    query->clear();
    qDebug() << "adding new income " <<
    query->prepare(QString("INSERT INTO income(id, date, income) "
                           "VALUES(:id, :date, :income)"));
    query->bindValue(":id", orderid);
    query->bindValue(":date", current_date);
    query->bindValue(":income", QString::number(income));
    query->exec();
}

// Метод удаления таблицы заказа из БД
void Database::deleteOrder(const QString &orderid)
{
    query->clear();
    qDebug() << "deleting order from orders: " << orderid << " " <<
    query->exec(QString("DELETE FROM orders WHERE id = '%1';").arg(orderid)); // удаляем заказ из таблицы заказов

    query->clear();
    qDebug() << "Finishing order " << orderid <<
    query->exec(QString("DROP table '%1'").arg(orderid)); // удаляем таблицу
}

double Database::findAllIncome()
{
    double allIncome = 0;
    query->clear();
    qDebug() << "opening income ";
    query->exec("SELECT income FROM income");

    while(query->next())
        allIncome += query->value(0).toDouble();
    return allIncome;
}

//------------------------------Методы_PARAMS------------------------------//

// Метод получения параметров заказа из БД
QList<QString> Database::getOrderParams(const QString &orderid)
{
    query->clear();
    qDebug() << "getting order params " <<
    query->prepare("SELECT * FROM orders WHERE id = :id");
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

// Метод добавления нового пластика
void Database::addPlastic(const QString &plastic, const double &cost)
{
    query->clear();

    qDebug() << "Adding new param " <<
    query->prepare("INSERT INTO params(plastic, cost) "
                   "VALUES(:plastic, :cost)");
    query->bindValue(":plastic", plastic);
    query->bindValue(":cost", cost);
    query->exec();
}

// Метод удаления пластика
void Database::deletePlastic(const QString &plastic)
{
    query->clear();

    qDebug() << "Deleting plastic " << plastic << " " <<
    query->exec(QString("DELETE FROM params WHERE plastic = '%1';").arg(plastic));
}

bool Database::findPlastic(const QString &plastic)
{
    query->clear();

    qDebug() << "bool params " <<
    query->prepare("SELECT * FROM params WHERE plastic = :name");
    query->bindValue(":name", plastic);
    query->exec();

    rec = query->record();
    query->next();
    QString m_plastic = query->value(rec.indexOf("plastic")).toString();
    return (plastic == m_plastic);
}

// Метод получения списка пластиков
QMap<QString, double> Database::getPlastics()
{
    QMap<QString, double> plastics; // создаем словарь пластиков
    query->clear();

    // Запрос на выбор параметров в БД
    qDebug() << "trying to select params: " <<
    query->exec("SELECT plastic, cost FROM params");

    while(query->next()) // заполняем словарь до конца таблицы
    {
        plastics.insert(query->value(0).toString(), query->value(1).toDouble());
    }

    return plastics;
}

//  Метод получения списка имен пластиков
QList<QString> Database::getPlasticNames()
{
    QList<QString> plastics_names;
    query->clear();

    qDebug() << "trying to get plastics names: " <<
    query->exec("SELECT plastic FROM params");

    while(query->next())
        plastics_names.append(query->value(0).toString());
    return plastics_names;
}

// Метод создания тестовых параметров печати
void Database::initTestPrintParams()
{
    addPlastic("PLA", 2.2);
    addPlastic("MDA", 1.5);
    addPlastic("STA", 3);
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
    qDebug() << "searchUser " <<
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
    qDebug() << "checkLogData " <<
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
    qDebug() << "getUserParams " <<
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
