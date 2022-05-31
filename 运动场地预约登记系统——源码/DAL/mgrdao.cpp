#include "mgrdao.h"

QSqlQueryModel *MgrDAO::getFieldModelByAll()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from Field");
    model->setHeaderData(0,Qt::Horizontal,"场地编号");
    model->setHeaderData(1,Qt::Horizontal,"场地名称");
    model->setHeaderData(2,Qt::Horizontal,"场地类型");
    model->setHeaderData(3,Qt::Horizontal,"场地地点");
    model->setHeaderData(4,Qt::Horizontal,"场地费用/小时");
    return model;
}

bool MgrDAO::addField(QString Id, QString Name, QString Type, QString Addr, float Fee)
{
    QSqlQuery query;
    query.prepare("insert into Field values(:FId,:FName,:FType,:FAddr,:FFee)");
    query.bindValue(":FId",Id);
    query.bindValue(":FName",Name);
    query.bindValue(":FType",Type);
    query.bindValue(":FAddr",Addr);
    query.bindValue(":FFee",Fee);
    return query.exec();
}

QSqlQueryModel *MgrDAO::getFiledModelByName(QString name)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from Field where Fname='"+name+"'");
    model->setHeaderData(0,Qt::Horizontal,"场地编号");
    model->setHeaderData(1,Qt::Horizontal,"场地名称");
    model->setHeaderData(2,Qt::Horizontal,"场地类型");
    model->setHeaderData(3,Qt::Horizontal,"场地地点");
    model->setHeaderData(4,Qt::Horizontal,"场地费用/小时");
    return model;
}

QSqlQueryModel *MgrDAO::getStatisticFMbrFUsingModelByAll()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from F_MBR_FUSing order by FName,FType,MGRName");
    model->setHeaderData(0,Qt::Horizontal,"场地名称");
    model->setHeaderData(1,Qt::Horizontal,"场地类型");
    model->setHeaderData(2,Qt::Horizontal,"管理人员");
    model->setHeaderData(3,Qt::Horizontal,"使用会员");
    model->setHeaderData(4,Qt::Horizontal,"使用开始时间");
    return model;
}

bool MgrDAO::modifyField(QString Id, QString Name, QString Type, QString Addr, float Fee)
{
    QSqlQuery query;
    query.prepare("update Field set Fname=:FName,FType=:FType,FAddr=:FAddr,FFee=:FFee where FId=:Id");
    query.bindValue(":FName",Name);
    query.bindValue(":FType",Type);
    query.bindValue(":FAddr",Addr);
    query.bindValue(":FFee",Fee);
    query.bindValue(":Id",Id);
    return  query.exec();
}

bool MgrDAO::deleteFiledById(QString Id)
{
    QSqlQuery query;
    query.prepare("delete Field where FId=:FId");
    query.bindValue(":FId",Id);
    return query.exec();
}

QSqlQueryModel *MgrDAO::getMgrFieldModelById(QString Id)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select MGRId,MGRName,MGRTele,Fname from MGR_F_SA where MGRId='"+Id+"'");
    return model;
}
