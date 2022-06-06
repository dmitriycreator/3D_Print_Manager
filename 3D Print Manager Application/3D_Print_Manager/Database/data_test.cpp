#include "database.h"

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
    }  catch (const QSqlError &e) {
        qDebug() << e;
    }
    return;
}
