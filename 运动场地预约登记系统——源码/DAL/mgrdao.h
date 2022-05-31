#ifndef MGRDAO_H
#define MGRDAO_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>

class MgrDAO
{
public:

    static QSqlQueryModel *getFieldModelByAll();

    static bool addField(QString Id,QString Name,QString Type,QString Addr,float Fee);

    static QSqlQueryModel *getFiledModelByName(QString name);

    static QSqlQueryModel *getStatisticFMbrFUsingModelByAll();

    static bool modifyField(QString Id,QString Name,QString Type,QString Addr,float Fee);

    static bool deleteFiledById(QString Id);

    static QSqlQueryModel *getMgrFieldModelById(QString Id);

};

#endif // MGRDAO_H
