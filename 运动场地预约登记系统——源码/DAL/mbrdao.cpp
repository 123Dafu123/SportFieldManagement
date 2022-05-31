#include "mbrdao.h"


QSqlQueryModel *MbrDAO::getFieldFreeModelByAll()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from F_FU_Free");
    model->setHeaderData(0,Qt::Horizontal,"场地编号");
    model->setHeaderData(1,Qt::Horizontal,"场地名称");
    model->setHeaderData(2,Qt::Horizontal,"场地类型");
    model->setHeaderData(3,Qt::Horizontal,"场地地点");
    model->setHeaderData(4,Qt::Horizontal,"场地费用/小时");
    return model;
}

QSqlQueryModel *MbrDAO::getFieldFreeModelByName(QString name)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from F_FU_Free where Fname='"+name+"'");
    model->setHeaderData(0,Qt::Horizontal,"场地编号");
    model->setHeaderData(1,Qt::Horizontal,"场地名称");
    model->setHeaderData(2,Qt::Horizontal,"场地类型");
    model->setHeaderData(3,Qt::Horizontal,"场地地点");
    model->setHeaderData(4,Qt::Horizontal,"场地费用/小时");
    return model;
}

QSqlQueryModel *MbrDAO::getFusingModelByMBRId(QString MBRId)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from FUSing where MBRId='"+MBRId+"'");
    return model;
}

QSqlQueryModel *MbrDAO::getFsuingModelByFId(QString FId)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from FUSing where FId='"+FId+"'");
    return model;
}

QSqlQueryModel *MbrDAO::getFieldModelByFId(QString FId)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from Field where FId='"+FId+"'");
    return model;
}

bool MbrDAO::addFusing(QString FUSTime, QString MBRId, QString FId)
{
    QSqlQuery query;
    query.prepare("insert into FUSing(FUSTime,MBRId,FId) values(:FUSTime,:MBRId,:FId)");
    query.bindValue(":FUSTime",FUSTime);
    query.bindValue(":MBRId",MBRId);
    query.bindValue(":FId",FId);
    return query.exec();
}

bool MbrDAO::deleteFusingByFId(QString FId)
{
    QSqlQuery query;
    query.prepare("delete from FUSing where FId=:FId");
    query.bindValue(":FId",FId);
    return query.exec();
}

bool MbrDAO::updateMbrBalaByMBRId(QString MBRId, float bala)
{
    QSqlQuery query;
    query.prepare("update Member set MBRBala=:bala where MBRId=:MBRId");
    query.bindValue(":MBRId",MBRId);
    query.bindValue(":bala",bala);
    return query.exec();
}

QSqlQueryModel *MbrDAO::getMbrModelById(QString Id)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from Member where MBRId='"+Id+"'");
    return model;
}
