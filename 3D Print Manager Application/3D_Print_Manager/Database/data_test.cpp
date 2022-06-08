#include "database.h"

// Тест для проверки работы БД
void data_test()
{
    try {
        Database data;
        data.connectToDatabase("C:/Users/User/Desktop/Data.db");
        QList<QString> params;
        params.append("march");
        params.append("2002");
        params.append("manager");
        data.addUser(params);
        data.addUser({"dima", "2002", "manager"});
        data.addUser({"ilya", "2002", "manager"});
        qDebug() << "searchUser: " << data.searchUser("march");
        qDebug() << "checkLog: " << data.checkLogData("march", "2002");
        QList<QString> check = data.getUserParams("ilya");
        qDebug() << check;
        data.deleteUser("dima");
        data.createNewOrder("test0");
        data.createNewOrder("test1");
        data.createNewOrder("test2");
        data.addPrint("1", {"name", "1", "2,2", "2,2", "PLA", "1", "1", "2,2"});
        data.deletePrint("1", "1");
        data.addPlastic("PLA", 2.2);
        data.addPlastic("LPA", 3.3);
        QMap<QString, double> plastics = data.getPlastics();
        qDebug() << "Plastics: " << plastics;
        data.deletePlastic("PLA");
    }  catch (const QSqlError &e) {
        qDebug() << e;
    }
    return;
}
