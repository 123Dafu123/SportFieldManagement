#ifndef LOGDAO_H
#define LOGDAO_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QDateTime>
#include <QString>
#include "DAL/dbconnection.h"

class LogDAO
{
public:
    static QSqlQueryModel *getMbrLogModelByIdAndPswd(QString Id,QString Pswd);

    static QSqlQueryModel *getMgrLogModelById(QString Id);

    static QSqlQueryModel *getSysLogModelById(QString Id);

};

#endif // LOGDAO_H
