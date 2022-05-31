#include "dbconnection.h"

QSqlDatabase DBConnection::SportDB=*(new QSqlDatabase);

bool DBConnection::getConnection()
{
    SportDB=QSqlDatabase::addDatabase("QODBC");
    SportDB.setHostName("localhost");
    SportDB.setDatabaseName("SportField");
    SportDB.setUserName("sa");
    SportDB.setPassword("wanghaozhe@@@1");
    return SportDB.open();
}

void DBConnection::closeConnection()
{
    SportDB.close();
    QSqlDatabase::removeDatabase("SportFiled");
}

