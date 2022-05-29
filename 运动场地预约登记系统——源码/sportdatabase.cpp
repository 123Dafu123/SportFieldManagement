#include "sportdatabase.h"

SportDataBase::SportDataBase()
{
    SportDB=QSqlDatabase::addDatabase("QODBC");
    SportDB.setHostName("localhost");
    SportDB.setDatabaseName("SportField");
    SportDB.setUserName("sa");
    SportDB.setPassword("wanghaozhe@@@1");
    SportDB.open();
}

bool SportDataBase::checkMbrLog(QString Id,QString Pswd)
{
    QSqlQuery querry;
    querry.prepare("select * from Member where MBRId=:Id and MBRPswd=:Pswd");
    querry.bindValue(":Id",Id);
    querry.bindValue(":Pswd",Pswd);
    querry.exec();
    int rowNum=0;
    while(querry.next())
    {
        for(int i=0;i<querry.record().count();i++){

        }
        rowNum++;
    }
    if(rowNum!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SportDataBase::checkMgrLog(QString Id)
{
    QSqlQuery querry;
    querry.prepare("select * from Manager where MGRId=:Id");
    querry.bindValue(":Id",Id);
    querry.exec();
    int rowNum=0;
    while(querry.next())
    {
        for(int i=0;i<querry.record().count();i++){

        }
        rowNum++;
    }
    if(rowNum!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SportDataBase::checkSysLog(QString Id)
{
    QSqlQuery querry;
    querry.prepare("select * from SysAdmin where SAId=:Id");
    querry.bindValue(":Id",Id);
    querry.exec();
    int rowNum=0;
    while(querry.next())
    {
        for(int i=0;i<querry.record().count();i++){

        }
        rowNum++;
    }
    if(rowNum!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SportDataBase::regMbr(QString Id,QString Pswd,QString Name,QString Tele)
{
    QSqlQuery querry1;

    querry1.prepare("insert into Member(MBRId,MBRName,MBRTele,MBRPswd) values(:Id,:Name,:Tele,:Pswd)");
    querry1.bindValue(":Id",Id);
    querry1.bindValue(":Name",Name);
    querry1.bindValue(":Tele",Tele);
    querry1.bindValue(":Pswd",Pswd);

    return querry1.exec();
}

bool SportDataBase::AddMgr(QString MGRId,QString MGRName,QString MGRTele,QString FName,QString SAId)
{
    QSqlQuery query,query1;
    QString FId;
    query1.prepare("select FId from Field where Fname=:FName");
    query1.bindValue(":FName",FName);
    if(!query1.exec())return false;
    if(!query1.next()&&FName!="")return false;
    FId=query1.value(0).toString();
    query.prepare("insert into Manager values(:MGRId,:MGRName,:MGRTele,:FId,:SAId)");
    query.bindValue(":MGRId",MGRId);
    query.bindValue(":MGRName",MGRName);
    query.bindValue(":MGRTele",MGRTele);
    query.bindValue(":FId",FId);
    query.bindValue(":SAId",SAId);
    return query.exec();
}

QSqlQueryModel* SportDataBase::getAllMgrFSaModel()
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

QSqlQueryModel* SportDataBase::searchMgrFSaModelbyMGRName(QString MGRName)
{
    QSqlQuery query;
    QSqlQueryModel *model=new QSqlQueryModel;

    query.prepare("select MGRId,MGRName,MGRTele,Fname,SAName from MGR_F_SA where MGRName=:MGRName");
    query.bindValue(":MGRName",MGRName);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,"编号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"电话");
    model->setHeaderData(3,Qt::Horizontal,"管理场地");
    model->setHeaderData(4,Qt::Horizontal,"所属系统管理员");
    return model;
}

bool SportDataBase::modifyMGR(QString modelId,QString MGRId,QString MGRName,QString MGRTele,QString FName,QString SAName)
{
    QString SAId,FId;
    QSqlQuery query,query1,query2;
    query1.prepare("select FId from Field where Fname=:FName");
    query1.bindValue(":FName",FName);
    if(!query1.exec())return false;
    if(!query1.next()&&FName!="")return false;
    FId=query1.value(0).toString();

    query2.prepare("select SAId from SysAdmin where SAName=:SAName");
    query2.bindValue(":SAName",SAName);
    if(!query2.exec())return false;
    query2.next();
    SAId=query2.value(0).toString();

    query.prepare("update MGR_F_SA set MGRId=:MGRId,MGRName=:MGRName,MGRTele=:MGRTele,SAId=:SAId,FId=:FId where MGRId=:modelId");
    query.bindValue(":MGRId",MGRId);
    query.bindValue(":MGRName",MGRName);
    query.bindValue(":MGRTele",MGRTele);
    query.bindValue(":SAId",SAId);
    query.bindValue(":FId",FId);
    query.bindValue(":modelId",modelId);
    return query.exec();
}

bool SportDataBase::deleteMgrbyMGRId(QString MGRId)
{
    QSqlQuery query;
    query.prepare("delete from Manager where MGRId=:MGRId");
    query.bindValue(":MGRId",MGRId);
    return query.exec();
}

QString SportDataBase::getSysName(QString SysId)
{
    QSqlQuery query;
    query.prepare("select SAName from SysAdmin where SAId=:SysId");
    query.bindValue(":SysId",SysId);
    query.exec();
    query.next();
    qDebug()<<query.value(0).toString();
    return query.value(0).toString();
}
QString SportDataBase::getSysTele(QString SysId)
{
    QSqlQuery query;
    query.prepare("select SATele from SysAdmin where SAId=:SysId");
    query.bindValue(":SysId",SysId);
    query.exec();
    query.next();
    return query.value(0).toString();
}

QString SportDataBase::getMbrPswd(QString MBRId)
{
    QSqlQuery query;
    query.prepare("select MBRPswd from Member where MBRId=:MBRId");
    query.bindValue(":MBRId",MBRId);
    query.exec();
    query.next();
    return query.value(0).toString();
}

QString SportDataBase::getMbrName(QString MBRId)
{
    QSqlQuery query;
    query.prepare("select MBRName from Member where MBRId=:MBRId");
    query.bindValue(":MBRId",MBRId);
    query.exec();
    query.next();
    return query.value(0).toString();
}

QString SportDataBase::getMbrTele(QString MBRId)
{
    QSqlQuery query;
    query.prepare("select MBRTele from Member where MBRId=:MBRId");
    query.bindValue(":MBRId",MBRId);
    query.exec();
    query.next();
    return query.value(0).toString();
}

float SportDataBase::getMbrBala(QString MBRId)
{
    QSqlQuery query;
    query.prepare("select MBRBala from Member where MBRId=:MBRId");
    query.bindValue(":MBRId",MBRId);
    query.exec();
    query.next();
    return query.value(0).toFloat();
}

QSqlQueryModel *SportDataBase::getAllFFUFreeModel()
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

QString SportDataBase::getMbrOrderSta(QString MBRId)
{
    QSqlQuery query;
    query.prepare("select distinct * from FUSing where MBRId=:MBRId");
    query.bindValue(":MBRId",MBRId);
    query.exec();
    int rowNum=0;
    while(query.next())
    {
        for(int i=0;i<query.record().count();i++){

        }
        rowNum++;
    }
    if(rowNum!=0)
    {
        return "使用中";
    }
    else
    {
        return "未预约";
    }
}

QSqlQueryModel *SportDataBase::searchFFUFreeModelByFName(QString FName)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("select * from F_FU_Free where Fname=:FName");
    query.bindValue(":FName",FName);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,"场地编号");
    model->setHeaderData(1,Qt::Horizontal,"场地名称");
    model->setHeaderData(2,Qt::Horizontal,"场地类型");
    model->setHeaderData(3,Qt::Horizontal,"场地地点");
    model->setHeaderData(4,Qt::Horizontal,"场地费用/小时");
    return model;
}

bool SportDataBase::rechargeMbr(QString MBRId,float count)
{
    QSqlQuery query;
    query.prepare("update Member set MBRBala+=:count where MBRId=:MBRId");
    query.bindValue(":count",count);
    query.bindValue(":MBRId",MBRId);
    return query.exec();
}

bool SportDataBase::orderField(QString MBRId, QString FId)
{
    QSqlQuery query;
    QDateTime dateTime=QDateTime::currentDateTime();
    query.prepare("insert into FUSing(FUSTime,MBRId,FId) values(:FUSTime,:MBRId,:FId)");
    query.bindValue(":FUSTime",QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss"));
    query.bindValue(":MBRId",MBRId);
    query.bindValue(":FId",FId);
    return query.exec();
}

QDateTime SportDataBase::getOrderSTime(QString MBRId)
{
    QSqlQuery query;

    query.prepare("select FUStime from FUSing where MBRId=:MBRId");
    query.bindValue(":MBRId",MBRId);
    query.exec();
    query.next();
    return query.value(0).toDateTime();
}

float SportDataBase::getOrderFFee(QString MBRId)
{
    QSqlQuery query,query1;
    QString FId;

    query.prepare("select FId from FUSing where MBRId=:MBRId");
    query.bindValue(":MBRId",MBRId);
    query.exec();
    query.next();
    FId=query.value(0).toString();
    query1.prepare("select FFee from Field where FId=:FId");
    query1.bindValue(":FId",FId);
    query1.exec();
    query1.next();
    return query1.value(0).toFloat();
}

float SportDataBase::getOrderCount(QString MBRId)
{
    qint64 stime=-QDateTime::currentDateTime().secsTo(getOrderSTime(MBRId));
    qint64 htime=stime/3600;
    if(stime%3600>1800)
    {
        htime++;
    }
    return getOrderFFee(MBRId)*htime;
}

bool SportDataBase::orderEndandPay(QString MBRId, float count)
{
    QSqlQuery query,query1;
    query.prepare("exec pay @fee=:count,@id=:MBRId");
    query.bindValue(":count",count);
    query.bindValue(":MBRId",MBRId);

    query1.prepare("delete from FUSing where MBRId=:MBRId");
    query1.bindValue(":MBRId",MBRId);
    return query1.exec()&&query.exec();
}

QString SportDataBase::getMgrName(QString MGRId)
{
    QSqlQuery query;
    query.prepare("select MGRName from MGR_F_SA where MGRId=:MGRId");
    query.bindValue(":MGRId",MGRId);
    query.exec();
    query.next();
    return query.value(0).toString();
}

QString SportDataBase::getMgrTele(QString MGRId)
{
    QSqlQuery query;
    query.prepare("select MGRTele from MGR_F_SA where MGRId=:MGRId");
    query.bindValue(":MGRId",MGRId);
    query.exec();
    query.next();
    return query.value(0).toString();
}

QString SportDataBase::getMgrFName(QString MGRId)
{
    QSqlQuery query;
    query.prepare("select Fname from MGR_F_SA where MGRId=:MGRId");
    query.bindValue(":MGRId",MGRId);
    query.exec();
    query.next();
    return query.value(0).toString();
}

QSqlQueryModel* SportDataBase::getAllFModel()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from Field");
    model->setHeaderData(0,Qt::Horizontal,"场地编号");
    model->setHeaderData(1,Qt::Horizontal,"场地名称");
    model->setHeaderData(2,Qt::Horizontal,"场地类型");
    model->setHeaderData(3,Qt::Horizontal,"场地地点");
    model->setHeaderData(4,Qt::Horizontal,"场地费用/小时");
    return model;
}

bool SportDataBase::addField(QString FId, QString FName, QString FType, QString FAddr, float FFee)
{
    QSqlQuery query;
    query.prepare("insert into Field values(:FId,:FName,:FType,:FAddr,:FFee)");
    query.bindValue(":FId",FId);
    query.bindValue(":FName",FName);
    query.bindValue(":FType",FType);
    query.bindValue(":FAddr",FAddr);
    query.bindValue(":FFee",FFee);
    return query.exec();
}

QSqlQueryModel *SportDataBase::searchFModelbyName(QString FName)
{
    QSqlQuery query;
    query.prepare("select * from Field where Fname=:FName");
    query.bindValue(":FName",FName);
    query.exec();
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,"场地编号");
    model->setHeaderData(1,Qt::Horizontal,"场地名称");
    model->setHeaderData(2,Qt::Horizontal,"场地类型");
    model->setHeaderData(3,Qt::Horizontal,"场地地点");
    model->setHeaderData(4,Qt::Horizontal,"场地费用/小时");
    return model;
}

bool SportDataBase::modfiyField(QString modId,QString FName, QString FType, QString FAddr, float FFee)
{
    QSqlQuery query;
    query.prepare("update Field set Fname=:FName,FType=:FType,FAddr=:FAddr,FFee=:FFee where FId=:modId");
    query.bindValue(":FName",FName);
    query.bindValue(":FType",FType);
    query.bindValue(":FAddr",FAddr);
    query.bindValue(":FFee",FFee);
    query.bindValue(":modId",modId);
    return  query.exec();
}

bool SportDataBase::deleteField(QString FId)
{
    QSqlQuery query;
    query.prepare("delete Field where FId=:FId");
    query.bindValue(":FId",FId);
    return query.exec();
}

QSqlQueryModel *SportDataBase::statisticFUSingModel()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    model->setQuery("select * from F_MBR_FUSing order by FName,FType,MGRName");
    model->setHeaderData(0,Qt::Horizontal,"场地名称");
    model->setHeaderData(1,Qt::Horizontal,"场地类型");
    model->setHeaderData(2,Qt::Horizontal,"管理人员");
    model->setHeaderData(3,Qt::Horizontal,"使用会员");
    model->setHeaderData(4,Qt::Horizontal,"使用开始时间");
    return model;
}
