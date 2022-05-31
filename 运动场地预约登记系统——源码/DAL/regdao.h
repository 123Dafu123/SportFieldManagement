#ifndef REGDAO_H
#define REGDAO_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>

class RegDAO
{
public:
    static bool regMbr(QString Id, QString Pswd, QString Name, QString Tele);
};

#endif // REGDAO_H
