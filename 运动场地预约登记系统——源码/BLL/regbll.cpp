#include "regbll.h"

bool RegBLL::regMbr(QString Id, QString Pswd, QString Name, QString Tele)
{
    return RegDAO::regMbr(Id,Pswd,Name,Tele);
}
