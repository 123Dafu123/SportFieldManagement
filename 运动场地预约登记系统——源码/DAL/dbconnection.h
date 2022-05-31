#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QSqlDatabase>

class DBConnection
{
private:
    static QSqlDatabase SportDB;

public:
    static bool getConnection();

    static void closeConnection();

};

#endif // DBCONNECTION_H
