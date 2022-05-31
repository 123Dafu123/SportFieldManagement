#include "regdao.h"

bool RegDAO::regMbr(QString Id, QString Pswd,QString Name,QString Tele)
{
    QSqlQuery *query=new QSqlQuery;

    query->prepare("insert into Member(MBRId,MBRName,MBRTele,MBRPswd) values(:Id,:Name,:Tele,:Pswd)");
    query->bindValue(":Id",Id);
    query->bindValue(":Name",Name);
    query->bindValue(":Tele",Tele);
    query->bindValue(":Pswd",Pswd);
    bool regSta = query->exec();
    delete query;
    query=nullptr;
    return regSta;
}
