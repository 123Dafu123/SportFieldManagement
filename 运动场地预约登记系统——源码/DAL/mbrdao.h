#ifndef MBRDAO_H
#define MBRDAO_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>

class MbrDAO
{
public:

    static QSqlQueryModel *getFieldFreeModelByAll();

    static QSqlQueryModel *getFieldFreeModelByName(QString name);

    static QSqlQueryModel *getFusingModelByMBRId(QString MBRId);

    static QSqlQueryModel *getFsuingModelByFId(QString FId);

    static QSqlQueryModel *getFieldModelByFId(QString FId);

    static bool addFusing(QString FUSTime,QString MBRId,QString FId);

    static bool deleteFusingByFId(QString FId);

    static bool updateMbrBalaByMBRId(QString MBRId,float bala);

    static QSqlQueryModel *getMbrModelById(QString Id);

};

#endif // MBRDAO_H
