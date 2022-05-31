#ifndef MGRBLL_H
#define MGRBLL_H

#include <QString>
#include <QSqlQueryModel>
#include <DAL/mgrdao.h>

class MgrBLL
{
public:

    static void setAddFId(QString FId);

    static void setAddFName(QString FName);

    static void setAddFType(QString FType);

    static void setAddFAddr(QString FAddr);

    static void setAddFFee(float FFee);

    static bool addFeild();

    static QSqlQueryModel *getFiledByALL();

    static QSqlQueryModel *getFieldByName(QString FName);

    static bool deleteFieldById(QString FId);

    static bool modifyField(QString FId,QString FName,QString FType,QString FAddr,float FFee);

    static QSqlQueryModel *getStatisticFMbrFUsingModelByAll();

    static void setThisId(QString Id);

    static QString getThisId();

    static QString getThisName();

    static QString getThisTele();

    static QString getThisFName();
private:
    static QString AddFId;
    static QString AddFName;
    static QString AddFType;
    static QString AddFAddr;
    static float AddFFee;
    static QString thisId;

};

#endif // MGRBLL_H
