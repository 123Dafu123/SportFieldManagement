#ifndef SYSBLL_H
#define SYSBLL_H

#include <QString>
#include <QSqlQueryModel>
#include <DAL/sysdao.h>

class SysBLL
{
public:

    static bool addMgrFSA();

    static QSqlQueryModel *getMgrFSAModelByAll();

    static QSqlQueryModel *getMgrFSAModelByName(QString Name);

    static bool modifyMgrFSA(QString Id,QString Name,QString Tele,QString FName,QString SysName,QString ModId);

    static bool deleteMgrFSAById(QString Id);

    static void setAddId(QString Id);

    static void setAddName(QString Name);

    static void setAddTele(QString Tele);

    static void setAddFName(QString FName);

    static void setAddSysName(QString SysName);

    static void setThisId(QString Id);

    static QString getThisId();

    static QString getThisName();

    static QString getThisTele();

private:
    static QString AddId;
    static QString AddName;
    static QString AddTele;
    static QString AddFName;
    static QString AddSysName;
    static QString thisId;
};

#endif // SYSBLL_H
