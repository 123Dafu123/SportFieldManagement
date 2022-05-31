#ifndef SYSDAO_H
#define SYSDAO_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>

class SysDAO
{
public:

    static bool addMgrFSA(QString Id,QString Name,QString Tele,QString FName,QString SAId);

    static QSqlQueryModel *getMgrFSAModelByAll();

    static QSqlQueryModel *getMgrFSAModelByName(QString Name);

    static bool modifyMgrFSA(QString Id,QString Name,QString Tele,QString FName,QString SysName,QString ModId);

    static bool deleteMgrFSAById(QString Id);

    static QSqlQueryModel *getSysAdminModelById(QString Id);

};

#endif // SYSDAO_H
