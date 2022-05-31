#include "mbrbll.h"

QString MbrBLL::thisId="";

void MbrBLL::setThisId(QString newThisId)
{
    thisId=newThisId;
}

QString MbrBLL::getThisId()
{
    return thisId;
}

QString MbrBLL::getThisPswd()
{
    return MbrDAO::getMbrModelById(thisId)->index(0,4).data().toString();
}

QString MbrBLL::getThisName()
{
    return MbrDAO::getMbrModelById(thisId)->index(0,1).data().toString();
}

QString MbrBLL::getThisTele()
{
    return MbrDAO::getMbrModelById(thisId)->index(0,2).data().toString();
}

float MbrBLL::getThisBala()
{
    return MbrDAO::getMbrModelById(thisId)->index(0,3).data().toFloat();
}

QSqlQueryModel *MbrBLL::getFreeFieldModelByAll()
{
    return MbrDAO::getFieldFreeModelByAll();
}

QSqlQueryModel *MbrBLL::getFreeFieldModelByName(QString name)
{
    return MbrDAO::getFieldFreeModelByName(name);
}

QString MbrBLL::getMbrOrderSta()
{
    if(MbrDAO::getFusingModelByMBRId(thisId)->rowCount()!=0)
    {
        return "使用中";
    }
    else
    {
        return "未预约";
    }
}

bool MbrBLL::isFieldOrderer(QString FId)
{
    if(MbrDAO::getFsuingModelByFId(FId)->rowCount()==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool MbrBLL::orderField(QString FId)
{
    return MbrDAO::addFusing(QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss"),thisId,FId);
}

float MbrBLL::getOrderCount()
{
    qint64 stime=-QDateTime::currentDateTime().secsTo(MbrDAO::getFusingModelByMBRId(thisId)->index(0,1).data().toDateTime());
    qint64 htime=stime/3600;
    if(stime%3600>1800)
    {
        htime++;
    }
    return htime*MbrDAO::getFieldModelByFId(MbrDAO::getFusingModelByMBRId(thisId)->index(0,3).data().toString())->index(0,4).data().toFloat();
}

bool MbrBLL::endOrderFeild()
{

    float bala=getThisBala()-getOrderCount();
    if(bala<0)return false;
    return MbrDAO::deleteFusingByFId(MbrDAO::getFusingModelByMBRId(thisId)->index(0,3).data().toString())&&MbrDAO::updateMbrBalaByMBRId(thisId,bala);
}

bool MbrBLL::rechargeBala(float count)
{
    if(count<0)
    {
        return false;
    }
    else
    {
        return MbrDAO::updateMbrBalaByMBRId(thisId,getThisBala()+count);
    }
}
