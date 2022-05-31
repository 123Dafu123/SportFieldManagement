#include "logbll.h"



bool LogBLL::checkMbrLog(QString Id, QString Pswd)
{
    if(LogDAO::getMbrLogModelByIdAndPswd(Id,Pswd)->rowCount()>=1)return true;
    else return false;
}

bool LogBLL::checkMgrLog(QString Id)
{
    if(LogDAO::getMgrLogModelById(Id)->rowCount()>=1)return true;
    else return false;
}

bool LogBLL::checkSysLog(QString Id)
{
    if(LogDAO::getSysLogModelById(Id)->rowCount()>=1)return true;
    else return false;
}
