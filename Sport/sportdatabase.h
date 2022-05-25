#ifndef SPORTDATABASE_H
#define SPORTDATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QDateTime>

class SportDataBase
{
public:
    SportDataBase();
    bool checkMbrLog(QString Id,QString Pswd);
    bool checkMgrLog(QString Id);
    bool checkSysLog(QString Id);
    bool regMbr(QString Id,QString Pswd,QString Name,QString Tele);
    bool AddMgr(QString Id,QString Name,QString Tele,QString FName,QString SAId);
    QSqlQueryModel* getAllMgrFSaModel();
    QSqlQueryModel* searchMgrFSaModelbyMGRName(QString MGRName);
    bool modifyMGR(QString modelId,QString MGRId,QString MGRName,QString MGRTele,QString Fname,QString SAName);
    bool deleteMgrbyMGRId(QString MGRId);
    QString getSysName(QString SysId);
    QString getSysTele(QString SysId);
    QString getMbrPswd(QString MBRId);
    QString getMbrName(QString MBRId);
    QString getMbrTele(QString MBRId);
    float getMbrBala(QString MBRId);
    QSqlQueryModel* getAllFFUFreeModel();
    QString getMbrOrderSta(QString MBRId);
    QSqlQueryModel* searchFFUFreeModelByFName(QString FName);
    bool rechargeMbr(QString MBRId,float count);
    bool orderFeild(QString MBRId,QString FId);
    QDateTime getOrderSTime(QString MBRId);
    float getOrderFFee(QString MBRId);
    float getOrderCount(QString MBRId);
    bool orderEndandPay(QString MBRId,float count);
    QString getMgrName(QString MGRId);
    QString getMgrTele(QString MGRId);
    QString getMgrFName(QString MGRId);
    QSqlQueryModel* getAllFModel();
    bool addFeild(QString FId,QString FName,QString FType,QString FAddr,float FFee);
    QSqlQueryModel* searchFModelbyName(QString FName);
    bool modfiyFeild(QString modId,QString FName,QString FType,QString FAddr,float FFee);
    bool deleteFeild(QString FId);
    QSqlQueryModel* statisticFUSingModel();
private:
    QSqlDatabase SportDB;
};


#endif // SPORTDATABASE_H
