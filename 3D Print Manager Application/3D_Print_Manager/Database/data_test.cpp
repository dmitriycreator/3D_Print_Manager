#include "database.h"

void users_test()
{
    try {
        Database data;
        data.connectToUsersDB();
        QList<QString> params;
        params.append("march");
        params.append("2002");
        params.append("manager");
        data.addUser(params);
        qDebug() << "searchUser: " << data.searchUser("march");
        qDebug() << "checkLog: " << data.checkLogData("march", "2002");
        QList<QString> check = data.getUserParams("march");
        qDebug() << check;

    }  catch (const QSqlError &e) {
        qDebug() << e;
    }
}
