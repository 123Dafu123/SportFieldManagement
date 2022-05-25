#include "logform.h"
#include "ui_logform.h"

LogForm::LogForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogForm)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->sta=mbrSta;
    setFormSta();
    ui->MbrRb->setChecked(true);
}

LogForm::~LogForm()
{
    delete ui;
}
void LogForm::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
    isPressedWidget = true;
}


void LogForm::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget) {
        this->move(this->x() + (event->globalX() - m_lastPos.x()),
                   this->y() + (event->globalY() - m_lastPos.y()));
        m_lastPos = event->globalPos();
    }
}


void LogForm::mouseReleaseEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
    isPressedWidget = false;
}

void LogForm::on_CloseB_clicked()
{
    this->close();
}


void LogForm::on_MinB_clicked()
{
    this->showMinimized();
}


void LogForm::on_MbrRb_clicked()
{
    sta=mbrSta;
    setFormSta();
}


void LogForm::on_MgrRb_clicked()
{
    sta=mgrSta;
    setFormSta();
}


void LogForm::on_SysRb_clicked()
{
    sta=sysSta;
    setFormSta();
}


void LogForm::on_MbrLogB_clicked()
{
    log();
}


void LogForm::on_SysMgrLogB_clicked()
{
    log();
}


void LogForm::on_MbrRegB_clicked()
{
    regMbr();
}

void LogForm::on_IdT_returnPressed()
{
    log();
}

void LogForm::on_PswdT_returnPressed()
{
    log();
}


void LogForm::setFormSta()
{
    if(sta==mbrSta)
    {
        this->ui->IdT->show();
        this->ui->PswdT->show();
        this->ui->MbrLogB->show();
        this->ui->MbrRegB->show();
        this->ui->SysMgrLogB->close();
    }
    else
    {
        this->ui->IdT->show();
        this->ui->PswdT->close();
        this->ui->MbrLogB->close();
        this->ui->MbrRegB->close();
        this->ui->SysMgrLogB->show();
    }
}

void LogForm::log()
{
    QString id;
    QString pswd;
    if(sta==mbrSta)
    {
        id=this->ui->IdT->text();
        pswd=this->ui->PswdT->text();
        if(DB.checkMbrLog(id,pswd))
        {
            this->close();
            mbr=new MbrWindow;
            mbr->setMbrInfo(id);
            mbr->show();
            return;
        }
        else
        {
            ui->LogInfoL->setText("会员Id或者密码错误");
        }
    }
    else if(sta==mgrSta)
    {
        id=this->ui->IdT->text();
        if(DB.checkMgrLog(id))
        {
            mgr=new MgrWindow;
            mgr->setMgrinfo(id);
            mgr->show();
            this->close();
            return;
        }
        else
        {
            ui->LogInfoL->setText("场地管理员Id错误");
        }
    }
    else if(sta==sysSta)
    {
        id=this->ui->IdT->text();
        if(DB.checkSysLog(id))
        {
            sys=new SysWindow;
            sys->setSysInfo(id);
            sys->show();
            this->close();
            return;
        }
        else
        {
            ui->LogInfoL->setText("系统管理员Id错误");
        }
    }
}

void LogForm::regMbr()
{
    if(sta==mbrSta)
    {
        reg=new RegForm;
        reg->show();
    }
}
