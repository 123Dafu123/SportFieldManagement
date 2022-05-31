#include "sysdao.h"


bool SysDAO::addMgrFSA(QString Id, QString Name, QString Tele, QString FName, QString SAId)
{
    QSqlQuery query;

    query.prepare("insert into Manager values(:MGRId,:MGRName,:MGRTele,(select FId from Field where Fname=:FName),:SAId)");
    query.bindValue(":MGRId",Id);
    query.bindValue(":MGRName",Name);
    query.bindValue(":MGRTele",Tele);
    query.bindValue(":FName",FName);
    query.bindValue(":SAId",SAId);
    return query.exec();
}

QSqlQueryModel *SysDAO::getMgrFSAModelByAll()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select MGRId,MGRName,MGRTele,Fname,SAName from MGR_F_SA");
    model->setHeaderData(0,Qt::Horizontal,"编号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"电话");
    model->setHeaderData(3,Qt::Horizontal,"管理场地");
    model->setHeaderData(4,Qt::Horizontal,"所属系统管理员");
    return model;
}

QSqlQueryModel *SysDAO::getMgrFSAModelByName(QString Name)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select MGRId,MGRName,MGRTele,Fname,SAName from MGR_F_SA where MGRName='"+Name+"'");
    model->setHeaderData(0,Qt::Horizontal,"编号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"电话");
    model->setHeaderData(3,Qt::Horizontal,"管理场地");
    model->setHeaderData(4,Qt::Horizontal,"所属系统管理员");
    return model;
}

bool SysDAO::modifyMgrFSA(QString Id, QString Name, QString Tele, QString FName, QString SysName, QString ModId)
{
    QSqlQuery query;

    query.prepare("update MGR_F_SA set MGRId=:MGRId,MGRName=:MGRName,MGRTele=:MGRTele,SAId=(select SAId from SysAdmin where SAName=:SysName),FId=(select FId from Field where Fname=:FName) where MGRId=:modelId");
    query.bindValue(":MGRId",Id);
    query.bindValue(":MGRName",Name);
    query.bindValue(":MGRTele",Tele);
    query.bindValue(":SysName",SysName);
    query.bindValue(":FName",FName);
    query.bindValue(":modelId",ModId);
    return query.exec();
}

bool SysDAO::deleteMgrFSAById(QString Id)
{
    QSqlQuery query;
    query.prepare("delete from Manager where MGRId=:MGRId");
    query.bindValue(":MGRId",Id);
    return query.exec();
}

QSqlQueryModel *SysDAO::getSysAdminModelById(QString Id)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from SysAdmin where SAId='"+Id+"'");
    return model;
}
