#ifndef REGBLL_H
#define REGBLL_H

#include <QString>
#include <DAL/regdao.h>

class RegBLL
{
public:
    static bool regMbr(QString Id,QString Pswd,QString Name,QString Tele);
};

#endif // REGBLL_H
