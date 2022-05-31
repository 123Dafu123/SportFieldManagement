#ifndef LOGBLL_H
#define LOGBLL_H

#include <QString>
#include <DAL/logdao.h>


class LogBLL
{
public:

    static bool checkMbrLog(QString Id,QString Pswd);

    static bool checkMgrLog(QString Id);

    static bool checkSysLog(QString Id);
};

#endif // LOGBLL_H
