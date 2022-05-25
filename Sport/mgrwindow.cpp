#include "mgrwindow.h"
#include "ui_mgrwindow.h"

MgrWindow::MgrWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MgrWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    sta=FeildSta;
    setSta();
    ui->FeildRb->setChecked(true);
}

MgrWindow::~MgrWindow()
{
    delete ui;   
}

void MgrWindow::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
    isPressedWidget = true;
}


void MgrWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget) {
        this->move(this->x() + (event->globalX() - m_lastPos.x()),
                   this->y() + (event->globalY() - m_lastPos.y()));
        m_lastPos = event->globalPos();
    }
}


void MgrWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
    isPressedWidget = false;
}

void MgrWindow::on_MinB_clicked()
{
    this->showMinimized();
}


void MgrWindow::on_CloseB_clicked()
{
    this->close();
}


void MgrWindow::on_FeildRb_clicked()
{
    sta=FeildSta;
    setSta();
}


void MgrWindow::on_MgrInfoRb_clicked()
{

    sta=MgrInfoSta;
    setSta();
}



void MgrWindow::on_AddB_clicked()
{
    ui->InfoT->setText("");
    ui->InfoT->setPlaceholderText("输入编号");
    ui->WaringL->setText("请在文本框中输入增添的信息");
    ui->InfoT->show();
    ui->FinshB->show();
    finshModel=Add;
    addInfoSta=IdSta;
}


void MgrWindow::on_SearhB_clicked()
{
    ui->InfoT->setText("");
    ui->InfoT->setPlaceholderText("输入场地名进行查询");
    ui->WaringL->setText("请在文本框中输入查询的场地名");
    ui->InfoT->show();
    ui->FinshB->show();
    finshModel=Search;
}


void MgrWindow::on_StatisticB_clicked()
{
    ui->WaringL->setText("");
    ui->dataLV->setModel(DB.statisticFUSingModel());
    ui->InfoT->close();
    ui->FinshB->show();
    ui->AddB->setEnabled(false);
    ui->SearhB->setEnabled(false);
    ui->ModfiyB->setEnabled(false);
    ui->DeleteB->setEnabled(false);
    finshModel=Statistic;
}


void MgrWindow::on_ModfiyB_clicked()
{
    ui->WaringL->setText("单击选中表单中场地项目以修改");
    ui->InfoT->setText("");
    ui->InfoT->setPlaceholderText("输入修改内容");
    ui->InfoT->show();
    ui->FinshB->show();
    finshModel=Modfiy;
}


void MgrWindow::on_DeleteB_clicked()
{
    ui->WaringL->setText("单击选中表单中场地以删除");
    ui->InfoT->close();
    ui->FinshB->show();
    finshModel=Delete;
}


void MgrWindow::on_FinshB_clicked()
{
    if(finshModel==Add)
    {
        switch (addInfoSta)
        {
        case IdSta:
            if(ui->InfoT->text()==""||ui->InfoT->text()=="输入编号")
            {
                ui->WaringL->setText("请补全信息");
            }
            else
            {
                feildinfo.Id=ui->InfoT->text();
                ui->WaringL->setText("请在文本框中输入增添的信息");
                addInfoSta=NameSta;
                ui->InfoT->setText("");
                ui->InfoT->setPlaceholderText("输入场地名称");
            }

            break;
        case NameSta:
            if(ui->InfoT->text()==""||ui->InfoT->text()=="输入场地名称")
            {
                ui->WaringL->setText("请补全信息");
            }
            else
            {
                feildinfo.Name=ui->InfoT->text();
                ui->WaringL->setText("请在文本框中输入增添的信息");
                addInfoSta=TypeSta;
                ui->InfoT->setText("");
                ui->InfoT->setPlaceholderText("输入类型");
            }
            break;
        case TypeSta:
            if(ui->InfoT->text()==""||ui->InfoT->text()=="输入类型")
            {
                ui->WaringL->setText("请补全信息");
            }
            else
            {
                feildinfo.Type=ui->InfoT->text();
                ui->WaringL->setText("请在文本框中输入增添的信息");
                addInfoSta=AddrSta;
                ui->InfoT->setText("");
                ui->InfoT->setPlaceholderText("输入地址");
            }
            break;
        case AddrSta:
            if(ui->InfoT->text()==""||ui->InfoT->text()=="输入地址")
            {
                ui->WaringL->setText("请补全信息");
            }
            else
            {
                feildinfo.Addr=ui->InfoT->text();
                ui->WaringL->setText("请在文本框中输入增添的信息");
                addInfoSta=FeeSta;
                ui->InfoT->setText("");
                ui->InfoT->setPlaceholderText("输入费用");
            }

            break;
        case FeeSta:
            if(ui->InfoT->text()==""||ui->InfoT->text()=="输入费用")
            {
                ui->WaringL->setText("请补全信息");
            }
            else
            {
                feildinfo.Fee=ui->InfoT->text().toFloat();
                ui->WaringL->setText("请在文本框中输入增添的信息");
                addInfoSta=ExitSta;
                ui->InfoT->setText("");
                ui->WaringL->setText("");
                ui->InfoT->close();
                ui->FinshB->close();
                if(!DB.addFeild(feildinfo.Id,feildinfo.Name,feildinfo.Type,feildinfo.Addr,feildinfo.Fee))
                {
                    ui->WaringL->setText("增加失败，输入信息不符合规范,检查id是否重复");
                }
                else
                {
                    ui->WaringL->setText("增加成功");
                }
            }
        default:
            break;
        }
        ui->dataLV->setModel(DB.getAllFModel());

    }
    else if(finshModel==Search)
    {
        if(ui->InfoT->text()==""||ui->InfoT->text()=="输入场地名进行查询")
        {
            ui->WaringL->setText("请补全信息");
        }
        else
        {
            QString FName=ui->InfoT->text();
            ui->dataLV->setModel(DB.searchFModelbyName(FName));
            ui->InfoT->setText("");
            ui->WaringL->setText("搜索完成");
            ui->InfoT->close();
            ui->FinshB->close();

        }
    }
    else if(finshModel==Modfiy)
    {
        int modRow=ui->dataLV->currentIndex().row();
        int modCol=ui->dataLV->currentIndex().column();
        QString modFId=ui->dataLV->model()->index(modRow,0).data().toString();
        feildinfo.Id=ui->dataLV->model()->index(modRow,0).data().toString();
        feildinfo.Name=ui->dataLV->model()->index(modRow,1).data().toString();
        feildinfo.Type=ui->dataLV->model()->index(modRow,2).data().toString();
        feildinfo.Addr=ui->dataLV->model()->index(modRow,3).data().toString();
        feildinfo.Fee=ui->dataLV->model()->index(modRow,4).data().toFloat();
        if(ui->InfoT->text()==""||ui->InfoT->text()=="输入修改内容")
        {
            ui->WaringL->setText("请输入修改信息");
        }
        else if(modRow==-1)
        {
            ui->WaringL->setText("请单击选中修改的场地项目");
        }
        else if(modCol==0)
        {
            ui->WaringL->setText("场地编号不可修改");
            ui->InfoT->setText("");
            ui->InfoT->close();
            ui->FinshB->close();
        }
        else
        {
            switch (modCol)
            {
            case 1:
                feildinfo.Name=ui->InfoT->text();
                break;
            case 2:
                feildinfo.Type=ui->InfoT->text();
                break;
            case 3:
                feildinfo.Addr=ui->InfoT->text();
                break;
            case 4:
                feildinfo.Fee=ui->InfoT->text().toFloat();
                break;
            default:
                break;
            }
            if(!DB.modfiyFeild(modFId,feildinfo.Name,feildinfo.Type,feildinfo.Addr,feildinfo.Fee))
            {
                ui->WaringL->setText("输入数据不符合要求，修改失败");
            }
            else
            {
                ui->WaringL->setText("修改成功");
            }
            ui->InfoT->setText("");
            ui->InfoT->close();
            ui->FinshB->close();
        }
        ui->dataLV->setModel(DB.getAllFModel());
    }
    else if(finshModel==Delete)
    {
        int delRow=ui->dataLV->currentIndex().row();
        if(delRow==-1)
        {
            ui->WaringL->setText("请选择删除的场地");
        }
        else
        {
            if(!DB.deleteFeild(ui->dataLV->model()->index(delRow,0).data().toString()))
            {
                ui->WaringL->setText("场地使用中，不可删除");
            }
            else
            {
                ui->WaringL->setText("删除成功");
                ui->InfoT->close();
                ui->FinshB->close();
            }
        }
        ui->dataLV->setModel(DB.getAllFModel());
    }
    else if(finshModel==Statistic)
    {
        ui->WaringL->setText("");
        ui->InfoT->close();
        ui->FinshB->close();
        ui->AddB->setEnabled(true);
        ui->SearhB->setEnabled(true);
        ui->ModfiyB->setEnabled(true);
        ui->DeleteB->setEnabled(true);
        ui->dataLV->setModel(DB.getAllFModel());
    }

}

void MgrWindow::on_InfoT_returnPressed()
{
    on_FinshB_clicked();
}


void MgrWindow::setMgrinfo(QString MgrId)
{
    mgrinfo.Id=MgrId;
    mgrinfo.Name=DB.getMgrName(MgrId);
    mgrinfo.Tele=DB.getMgrTele(MgrId);
    mgrinfo.FName=DB.getMgrFName(MgrId);
}

void MgrWindow::setSta()
{
    if(sta==FeildSta)
    {
        ui->MgrStrL->setText("场地管理");
        ui->MgrStrL->show();
        ui->InfoT->close();
        ui->FinshB->close();
        ui->AddB->show();
        ui->SearhB->show();
        ui->StatisticB->show();
        ui->ModfiyB->show();
        ui->DeleteB->show();
        ui->dataLV->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->dataLV->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
        ui->dataLV->setModel(DB.getAllFModel());
        ui->dataLV->show();
        ui->WaringL->show();
        ui->IdL->close();
        ui->NameL->close();
        ui->TeleL->close();
        ui->FeildL->close();
        ui->WaringL->setText("");
    }
    else if(sta==MgrInfoSta)
    {
        ui->MgrStrL->setText("个人信息");
        ui->MgrStrL->show();
        ui->InfoT->close();
        ui->FinshB->close();
        ui->AddB->close();
        ui->SearhB->close();
        ui->StatisticB->close();
        ui->ModfiyB->close();
        ui->DeleteB->close();
        ui->dataLV->close();
        ui->WaringL->close();
        ui->IdL->setText("编号："+mgrinfo.Id);
        ui->NameL->setText("姓名："+mgrinfo.Name);
        ui->TeleL->setText("电话："+mgrinfo.Tele);
        ui->FeildL->setText("管理场地："+mgrinfo.FName);
        ui->IdL->show();
        ui->NameL->show();
        ui->TeleL->show();
        ui->FeildL->show();
        ui->WaringL->setText("");
    }

}



