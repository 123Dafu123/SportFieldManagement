#include "logdao.h"


QSqlQueryModel *LogDAO::getMbrLogModelByIdAndPswd(QString Id,QString Pswd)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from Member where MBRId='"+Id+"' and MBRPswd='"+Pswd+"'");
    return model;
}

QSqlQueryModel *LogDAO::getMgrLogModelById(QString Id)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from Manager where MGRId='"+Id+"'");
    return model;
}

QSqlQueryModel *LogDAO::getSysLogModelById(QString Id)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from SysAdmin where SAId='"+Id+"'");
    return model;
}
