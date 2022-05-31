#include "sysbll.h"

QString SysBLL::AddId="";
QString SysBLL::AddName="";
QString SysBLL::AddTele="";
QString SysBLL::AddFName="";
QString SysBLL::AddSysName="";
QString SysBLL::thisId="";

bool SysBLL::addMgrFSA()
{
    return SysDAO::addMgrFSA(AddId,AddName,AddTele,AddFName,thisId);
}

QSqlQueryModel *SysBLL::getMgrFSAModelByAll()
{
    return SysDAO::getMgrFSAModelByAll();
}

QSqlQueryModel *SysBLL::getMgrFSAModelByName(QString Name)
{
    return SysDAO::getMgrFSAModelByName(Name);
}

bool SysBLL::modifyMgrFSA(QString Id, QString Name, QString Tele, QString FName, QString SysName, QString ModId)
{
    return SysDAO::modifyMgrFSA(Id,Name,Tele,FName,SysName,ModId);
}

bool SysBLL::deleteMgrFSAById(QString Id)
{
    return SysDAO::deleteMgrFSAById(Id);
}

void SysBLL::setAddId(QString Id)
{
    AddId=Id;
}

void SysBLL::setAddName(QString Name)
{
    AddName=Name;
}

void SysBLL::setAddTele(QString Tele)
{
    AddTele=Tele;
}

void SysBLL::setAddFName(QString FName)
{
    AddFName=FName;
}

void SysBLL::setAddSysName(QString SysName)
{
    AddSysName=SysName;
}

void SysBLL::setThisId(QString Id)
{
    thisId=Id;
}

QString SysBLL::getThisId()
{
    return thisId;
}

QString SysBLL::getThisName()
{
    return SysDAO::getSysAdminModelById(thisId)->index(0,1).data().toString();
}

QString SysBLL::getThisTele()
{
    return SysDAO::getSysAdminModelById(thisId)->index(0,2).data().toString();
}
