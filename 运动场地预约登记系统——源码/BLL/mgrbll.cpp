#include "mgrbll.h"

QString MgrBLL::AddFId="";
QString MgrBLL::AddFName="";
QString MgrBLL::AddFType="";
QString MgrBLL::AddFAddr="";
float MgrBLL::AddFFee=0;
QString MgrBLL::thisId="";


void MgrBLL::setAddFId(QString FId)
{
    AddFId=FId;
}

void MgrBLL::setAddFName(QString FName)
{
    AddFName=FName;
}

void MgrBLL::setAddFType(QString FType)
{
    AddFType=FType;
}

void MgrBLL::setAddFAddr(QString FAddr)
{
    AddFAddr=FAddr;
}

void MgrBLL::setAddFFee(float FFee)
{
    AddFFee=FFee;
}

bool MgrBLL::addFeild()
{
    return MgrDAO::addField(AddFId,AddFName,AddFType,AddFAddr,AddFFee);
}

QSqlQueryModel *MgrBLL::getFiledByALL()
{
    return MgrDAO::getFieldModelByAll();
}

QSqlQueryModel *MgrBLL::getFieldByName(QString FName)
{
    return MgrDAO::getFiledModelByName(FName);
}

bool MgrBLL::deleteFieldById(QString FId)
{
    return MgrDAO::deleteFiledById(FId);
}

bool MgrBLL::modifyField(QString FId, QString FName, QString FType, QString FAddr, float FFee)
{
    return MgrDAO::modifyField(FId,FName,FType,FAddr,FFee);
}

QSqlQueryModel *MgrBLL::getStatisticFMbrFUsingModelByAll()
{
    return MgrDAO::getStatisticFMbrFUsingModelByAll();
}

void MgrBLL::setThisId(QString Id)
{
    thisId=Id;
}

QString MgrBLL::getThisId()
{
    return thisId;
}

QString MgrBLL::getThisName()
{
    return MgrDAO::getMgrFieldModelById(thisId)->index(0,1).data().toString();
}

QString MgrBLL::getThisTele()
{
    return MgrDAO::getMgrFieldModelById(thisId)->index(0,2).data().toString();
}

QString MgrBLL::getThisFName()
{
    return MgrDAO::getMgrFieldModelById(thisId)->index(0,3).data().toString();
}
