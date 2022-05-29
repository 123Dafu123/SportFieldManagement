#include "mbrwindow.h"
#include "ui_mbrwindow.h"

MbrWindow::MbrWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MbrWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    sta=FeildSta;
    setStatus();
    ui->FeildRb->setChecked(true);
}

MbrWindow::~MbrWindow()
{
    delete ui;
}

void MbrWindow::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
    isPressedWidget = true;
}


void MbrWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget) {
        this->move(this->x() + (event->globalX() - m_lastPos.x()),
                   this->y() + (event->globalY() - m_lastPos.y()));
        m_lastPos = event->globalPos();
    }
}


void MbrWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_lastPos = event->globalPos();
    isPressedWidget = false;
}

void MbrWindow::on_CloseB_clicked()
{
    this->close();
}


void MbrWindow::on_MinB_clicked()
{
    this->showMinimized();
}

void MbrWindow::on_FeildRb_clicked()
{
    sta=FeildSta;
    setStatus();
}


void MbrWindow::on_MbrInfoRb_clicked()
{
    sta=MbrInfoSta;
    setStatus();
}

void MbrWindow::on_RechargeB_clicked()
{
    ui->RechargeT->show();
    ui->RechargeB->close();
    ui->RechargeFinshB->show();
}


void MbrWindow::on_RechargeFinshB_clicked()
{
    QString text=ui->RechargeT->text();
    if(text=="")
    {
        ui->WaringL->setText("请输入充值金额");
        return;
    }
    float count=text.toFloat();
    if(count<=0)
    {
        ui->WaringL->setText("输入金额有误,充值失败");
        return;
    }
    if(DB.rechargeMbr(mbrinfo.Id,count))
    {
        ui->RechargeT->setText("");
        ui->RechargeT->setPlaceholderText("输入充值金额");
        ui->RechargeT->close();
        ui->RechargeB->show();
        ui->RechargeFinshB->close();
        ui->WaringL->setText("充值完成");
        mbrinfo.bala=DB.getMbrBala(mbrinfo.Id);
        ui->BalaL->setText("余额："+QString("%1").arg(mbrinfo.bala));
    }
    else
    {
        ui->WaringL->setText("充值失败");
    }
}

void MbrWindow::on_SearchB_clicked()
{
    if(ui->SearchT->text()==""||ui->SearchT->text()=="输入场地名称搜索")
    {
        ui->WaringL->setText("请补全搜索信息");
    }
    else
    {
        QString FName;
        FName=ui->SearchT->text();
        ui->dataLV->setModel(DB.searchFFUFreeModelByFName(FName));
        ui->SearchT->setText("");
        ui->SearchT->setPlaceholderText("输入场地名称搜索");
    }
}

void MbrWindow::on_OrderB_clicked()
{
    if(DB.getMbrOrderSta(mbrinfo.Id)=="使用中")
    {
        ui->WaringL->setText("您已经预约了场地，请结束使用后再预约");
        return;
    }
    int row=ui->dataLV->currentIndex().row();
    if(row==-1)
    {
        ui->WaringL->setText("请选择预约的场地");
    }
    else
    {
        QString FId=ui->dataLV->model()->index(row,0).data().toString();
        if(DB.orderField(mbrinfo.Id,FId))
        {
            ui->WaringL->setText("预约完成");
        }
        else
        {
            ui->WaringL->setText("预约失败");
        }
        ui->OrderStaL->setText("预约状态："+DB.getMbrOrderSta(mbrinfo.Id));
        ui->dataLV->setModel(DB.getAllFFUFreeModel());
    }

}

void MbrWindow::on_OrderEndB_clicked()
{
    if(DB.getMbrOrderSta(mbrinfo.Id)=="未预约")
    {
        ui->WaringL->setText("您还未预约");
        return;
    }
    else
    {
        float count=DB.getOrderCount(mbrinfo.Id);
        if(mbrinfo.bala<count)
        {
            ui->WaringL->setText("余额不足，请充值后再结束使用");
        }
        else
        {
            if(DB.orderEndandPay(mbrinfo.Id,count))
            {
                ui->WaringL->setText("本次使用已结束，欢迎下次预约。扣费："+QString("%1").arg(count)+"元。");
            }
            else
            {
                ui->WaringL->setText("结束使用失败，欢迎下次预约");
            }

        }


    }
    mbrinfo.bala=DB.getMbrBala(mbrinfo.Id);
    ui->OrderStaL->setText("预约状态："+DB.getMbrOrderSta(mbrinfo.Id));
    ui->dataLV->setModel(DB.getAllFFUFreeModel());
}

void MbrWindow::on_SearchT_returnPressed()
{
    on_SearchB_clicked();
}

void MbrWindow::on_RechargeT_returnPressed()
{
    on_RechargeFinshB_clicked();
}


void MbrWindow::setStatus()
{
    if(sta==FeildSta)
    {
        this->ui->MbrStrL->setText("场地预约");
        ui->OrderStaL->setText("预约状态："+DB.getMbrOrderSta(mbrinfo.Id));
        this->ui->OrderStaL->show();
        this->ui->OrderEndB->show();
        ui->dataLV->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
        ui->dataLV->setModel(DB.getAllFFUFreeModel());
        this->ui->dataLV->show();
        this->ui->IdL->close();
        this->ui->PswdL->close();
        this->ui->NameL->close();
        this->ui->TeleL->close();
        this->ui->BalaL->close();
        this->ui->SearchT->show();
        this->ui->SearchB->show();
        this->ui->OrderInfoL->show();
        this->ui->OrderB->show();
        this->ui->RechargeB->close();
        this->ui->RechargeT->close();
        this->ui->RechargeFinshB->close();
        this->ui->WaringL->setText("所有可预约场地均在表单中");
        this->ui->WaringL->show();
    }
    else if(sta==MbrInfoSta)
    {
        this->ui->MbrStrL->setText("个人信息");
        this->ui->OrderStaL->close();
        this->ui->OrderEndB->close();
        this->ui->dataLV->close();
        this->ui->IdL->setText("账号："+mbrinfo.Id);
        this->ui->PswdL->setText("密码："+mbrinfo.Pswd);
        this->ui->NameL->setText("用户名："+mbrinfo.Name);
        this->ui->TeleL->setText("电话："+mbrinfo.Tele);
        this->ui->BalaL->setText("余额："+QString("%1").arg(mbrinfo.bala));
        this->ui->IdL->show();
        this->ui->PswdL->show();
        this->ui->NameL->show();
        this->ui->TeleL->show();
        this->ui->BalaL->show();
        this->ui->SearchT->setText("");
        this->ui->SearchT->setPlaceholderText("输入场地名称搜索");
        this->ui->SearchT->close();
        this->ui->SearchB->close();
        this->ui->OrderInfoL->close();
        this->ui->OrderB->close();
        this->ui->RechargeB->show();
        this->ui->RechargeT->close();
        this->ui->RechargeFinshB->close();
        this->ui->WaringL->setText("");
        this->ui->WaringL->show();
    }
}

void MbrWindow::setMbrInfo(QString Id)
{
    mbrinfo.Id=Id;
    mbrinfo.Pswd=DB.getMbrPswd(Id);
    mbrinfo.Name=DB.getMbrName(Id);
    mbrinfo.Tele=DB.getMbrTele(Id);
    mbrinfo.bala=DB.getMbrBala(Id);
    ui->OrderStaL->setText("预约状态："+DB.getMbrOrderSta(mbrinfo.Id));
}








