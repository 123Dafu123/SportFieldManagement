#include "syswindow.h"
#include "ui_syswindow.h"

SysWindow::SysWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SysWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    sta=MgrSta;
    setSta();
    ui->MgrRb->setChecked(true);
}

SysWindow::~SysWindow()
{
    delete ui;
}

void SysWindow::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
    isPressedWidget = true;
}


void SysWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget) {
        this->move(this->x() + (event->globalX() - m_lastPos.x()),
                   this->y() + (event->globalY() - m_lastPos.y()));
        m_lastPos = event->globalPos();
    }
}


void SysWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
    isPressedWidget = false;
}

void SysWindow::on_MinB_clicked()
{
    this->showMinimized();
}


void SysWindow::on_CloseB_clicked()
{
    this->close();
}


void SysWindow::on_FinshB_clicked()
{
    if(finshModel==Add)
    {
        switch (addInfoSta)
        {
        case MgrIdSta:
            if(ui->InfoT->text()==""||ui->InfoT->text()=="输入场地管理员Id")
            {
                ui->WaringL->setText("请补全信息");
            }
            else
            {
                SysBLL::setAddId(ui->InfoT->text());
                addInfoSta=NameSta;
                ui->WaringL->setText("请在文本框中输入增添的信息");
                ui->InfoT->setText("");
                ui->InfoT->setPlaceholderText("输入场地管理员姓名");
            }
            break;
        case NameSta:
            if(ui->InfoT->text()==""||ui->InfoT->text()=="输入场地管理员姓名")
            {
                ui->WaringL->setText("请补全信息");
            }
            else
            {
                SysBLL::setAddName(ui->InfoT->text());
                ui->WaringL->setText("请在文本框中输入增添的信息");
                addInfoSta=TeleSta;
                ui->InfoT->setText("");
                ui->InfoT->setPlaceholderText("输入电话");
            }
            break;
        case TeleSta:
            if(ui->InfoT->text()==""||ui->InfoT->text()=="输入电话")
            {
                ui->WaringL->setText("请补全信息");
            }
            else
            {
                SysBLL::setAddTele(ui->InfoT->text());
                ui->WaringL->setText("请在文本框中输入增添的信息");
                addInfoSta=FIdSta;
                ui->InfoT->setText("");
                ui->InfoT->setPlaceholderText("输入管理场地的名称");
            }
            break;
        case FIdSta:
            if(ui->InfoT->text()=="输入管理场地的名称")
            {
                ui->WaringL->setText("请补全信息");
            }
            else
            {
                SysBLL::setAddFName(ui->InfoT->text());
                ui->WaringL->setText("请在文本框中输入增添的信息");

                addInfoSta=ExitSta;
                ui->InfoT->setText("");
                ui->InfoT->close();
                ui->FinshB->close();
                if(SysBLL::addMgrFSA())
                {
                    ui->WaringL->setText("添加成功");
                }
                else
                {
                    ui->WaringL->setText("添加失败，检查增添的管理员id是否重复");
                }
             }
        default:
            break;
        }
        ui->dataLV->setModel(SysBLL::getMgrFSAModelByAll());
    }
    else if(finshModel==Search)
    {
        if(ui->InfoT->text()==""||ui->InfoT->text()=="输入场地管理员姓名以查询")
        {
            ui->WaringL->setText("请输入查询信息");
        }
        else
        {
            ui->dataLV->setModel(SysBLL::getMgrFSAModelByName(ui->InfoT->text()));
            ui->InfoT->setText("");
            ui->WaringL->setText("查询完成");
            ui->InfoT->close();
            ui->FinshB->close();
        }
    }
    else if(finshModel==Modfiy)
    {
        int modRow=ui->dataLV->currentIndex().row();
        int modCol=ui->dataLV->currentIndex().column();
        QString modId=ui->dataLV->model()->index(modRow,0).data().toString();
        QString MgrId=ui->dataLV->model()->index(modRow,0).data().toString();
        QString Name=ui->dataLV->model()->index(modRow,1).data().toString();
        QString Tele=ui->dataLV->model()->index(modRow,2).data().toString();
        QString FName=ui->dataLV->model()->index(modRow,3).data().toString();
        QString SAName=ui->dataLV->model()->index(modRow,4).data().toString();
        if(ui->InfoT->text()==""||ui->InfoT->text()=="输入修改内容")
        {
            ui->WaringL->setText("请输入修改信息");
        }
        else if(modRow==-1)
        {
            ui->WaringL->setText("请单击选中修改的项目");
        }
        else
        {
            switch (modCol)
            {
            case 0:
                MgrId=ui->InfoT->text();
                break;
            case 1:
                Name=ui->InfoT->text();
                break;
            case 2:
                Tele=ui->InfoT->text();
                break;
            case 3:
                FName=ui->InfoT->text();
                break;
            case 4:
                SAName=ui->InfoT->text();
                break;
            default:
                break;
            }
            if(!SysBLL::modifyMgrFSA(MgrId,Name,Tele,FName,SAName,modId))
            {
                ui->WaringL->setText("输入数据不符合要求，修改失败");
            }
            else
            {
                ui->WaringL->setText("修改完成");
            }
            ui->InfoT->setText("");
            ui->InfoT->close();
            ui->FinshB->close();
        }
        ui->dataLV->setModel(SysBLL::getMgrFSAModelByAll());
    }
    else if(finshModel==Delete)
    {
        int delRow=ui->dataLV->currentIndex().row();
        if(delRow==-1)
        {
            ui->WaringL->setText("请单击选中需要删除的场地");
        }
        else
        {
            if(SysBLL::deleteMgrFSAById(ui->dataLV->model()->index(delRow,0).data().toString()))
            {
                ui->WaringL->setText("删除成功");
            }
            else
            {
                ui->WaringL->setText("删除失败");
            }
            ui->InfoT->setText("");
            ui->InfoT->close();
            ui->FinshB->close();
        }
        ui->dataLV->setModel(SysBLL::getMgrFSAModelByAll());
    }

}


void SysWindow::on_AddB_clicked()
{
    finshModel=Add;
    addInfoSta=MgrIdSta;
    ui->WaringL->setText("请在文本框中输入增添的信息");
    ui->InfoT->setText("");
    ui->InfoT->setPlaceholderText("输入场地管理员Id");
    ui->InfoT->show();
    ui->FinshB->show();
}


void SysWindow::on_SearhB_clicked()
{
    finshModel=Search;
    ui->WaringL->setText("请在文本框中输入查询的场地管理员姓名");
    ui->InfoT->setText("");
    ui->InfoT->setPlaceholderText("输入场地管理员姓名以查询");
    ui->InfoT->show();
    ui->FinshB->show();
}


void SysWindow::on_ModfiyB_clicked()
{
    finshModel=Modfiy;
    ui->WaringL->setText("单击选中表单中项目以修改");
    ui->InfoT->setText("");
    ui->InfoT->setPlaceholderText("输入修改内容");
    ui->InfoT->show();
    ui->FinshB->show();
}


void SysWindow::on_DeleteB_clicked()
{
    finshModel=Delete;
    ui->WaringL->setText("单击选中表单中管理员以删除");
    ui->InfoT->close();
    ui->FinshB->show();
}


void SysWindow::on_MgrRb_clicked()
{
    sta=MgrSta;
    setSta();
}


void SysWindow::on_SysInfoRb_clicked()
{
    sta=SysSta;
    setSta();
}

void SysWindow::on_InfoT_returnPressed()
{
    on_FinshB_clicked();
}


void SysWindow::setSta()
{
    if(sta==MgrSta)
    {
        ui->SysStrL->setText("人员管理");
        ui->SysStrL->show();
        ui->InfoT->close();
        ui->FinshB->close();
        ui->AddB->show();
        ui->SearhB->show();
        ui->ModfiyB->show();
        ui->DeleteB->show();
        ui->IdL->close();
        ui->NameL->close();
        ui->TeleL->close();
        ui->dataLV->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
        ui->dataLV->setModel(SysBLL::getMgrFSAModelByAll());
        ui->dataLV->show();
        ui->WaringL->show();
        ui->WaringL->setText("");
        ui->MgrRb->show();
        ui->SysInfoRb->show();
    }
    else if(sta==SysSta)
    {
        ui->SysStrL->setText("个人信息");
        ui->SysStrL->show();
        ui->InfoT->close();
        ui->FinshB->close();
        ui->AddB->close();
        ui->SearhB->close();
        ui->ModfiyB->close();
        ui->DeleteB->close();
        ui->IdL->setText("编号："+SysBLL::getThisId());
        ui->NameL->setText("姓名："+SysBLL::getThisName());
        ui->TeleL->setText("联系方式："+SysBLL::getThisTele());
        ui->IdL->show();
        ui->NameL->show();
        ui->TeleL->show();
        ui->dataLV->close();
        ui->WaringL->show();
        ui->WaringL->setText("");
        ui->MgrRb->show();
        ui->SysInfoRb->show();

    }
}
