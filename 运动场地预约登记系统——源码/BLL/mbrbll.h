#ifndef MBRBLL_H
#define MBRBLL_H

#include <QString>
#include <QDateTime>
#include <QSqlQueryModel>
#include <DAL/mbrdao.h>

class MbrBLL
{
public:
    static void setThisId(QString newThisId);

    static QString getThisId();

    static QString getThisPswd();

    static QString getThisName();

    static QString getThisTele();

    static float getThisBala();

    static QSqlQueryModel *getFreeFieldModelByAll();

    static QSqlQueryModel *getFreeFieldModelByName(QString name);

    static QString getMbrOrderSta();

    static bool orderField(QString FId);

    static bool isFieldOrderer(QString FId);

    static float getOrderCount();

    static bool endOrderFeild();

    static bool rechargeBala(float count);

private:
    static QString thisId;

};

#endif // MBRBLL_H
