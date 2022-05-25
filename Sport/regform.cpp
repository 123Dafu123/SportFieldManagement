#include "regform.h"
#include "ui_regform.h"

RegForm::RegForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegForm)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
}

RegForm::~RegForm()
{
    delete ui;
}

void RegForm::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
    isPressedWidget = true;
}


void RegForm::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget) {
        this->move(this->x() + (event->globalX() - m_lastPos.x()),
                   this->y() + (event->globalY() - m_lastPos.y()));
        m_lastPos = event->globalPos();
    }
}


void RegForm::mouseReleaseEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
    isPressedWidget = false;
}

void RegForm::on_CloseB_clicked()
{
    this->close();
}


void RegForm::on_MinB_clicked()
{
    this->showMinimized();
}


void RegForm::on_Reg_clicked()
{
    reg();
}


void RegForm::on_Cancel_clicked()
{
    this->close();
}

void RegForm::on_IdT_returnPressed()
{
    reg();
}


void RegForm::on_PswdT_returnPressed()
{
    reg();
}

void RegForm::on_NameT_returnPressed()
{
    reg();
}

void RegForm::on_TeleT_returnPressed()
{
    reg();
}

void RegForm::reg()
{
    QString id=this->ui->IdT->text();
    QString pswd=this->ui->PswdT->text();
    QString name=this->ui->NameT->text();
    QString tele=this->ui->TeleT->text();
    if(id==""||id=="输入Id"||pswd==""||pswd=="输入密码"||name==""||name=="输入用户名"||tele==""||tele=="输入电话号码")
    {
        ui->RegInfoL->setText("请补全信息");
    }
    else
    {
        if(DB.regMbr(id,pswd,name,tele))
        {
            this->close();
        }
        else
        {
            ui->RegInfoL->setText("Id重复或者输入的信息不符合规范");
        }
    }
}
