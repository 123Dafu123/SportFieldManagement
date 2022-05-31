#ifndef LOGFORM_H
#define LOGFORM_H

#include <QWidget>
#include <QIcon>
#include <QPoint>
#include <QMouseEvent>
#include <QList>
#include "Ui/mbrwindow.h"
#include "Ui/mgrwindow.h"
#include "Ui/syswindow.h"
#include "Ui/regform.h"
#include "BLL/logbll.h"
#include "BLL/mbrbll.h"
#include "BLL/mgrbll.h"
#include "BLL/sysbll.h"

namespace Ui {
class LogForm;
}

class LogForm : public QWidget
{
    Q_OBJECT

public:
    explicit LogForm(QWidget *parent = nullptr);
    ~LogForm();

protected:
    void mouseReleaseEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_CloseB_clicked();

    void on_MinB_clicked();

    void on_MbrRb_clicked();

    void on_MgrRb_clicked();

    void on_SysRb_clicked();

    void on_MbrLogB_clicked();

    void on_SysMgrLogB_clicked();

    void on_MbrRegB_clicked();


    void on_IdT_returnPressed();

    void on_PswdT_returnPressed();

private:
    bool isPressedWidget;
    QPoint m_lastPos;
    Ui::LogForm *ui;
    MbrWindow *mbr;
    MgrWindow *mgr;
    SysWindow *sys;
    RegForm *reg;
    enum Status
    {
        mbrSta=0x01,
        mgrSta=0x02,
        sysSta=0x03,
    }sta;

    void setFormSta();

    void log();

    void regMbr();
};

#endif // LOGFORM_H
