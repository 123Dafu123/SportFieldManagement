#ifndef SYSWINDOW_H
#define SYSWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>
#include "BLL/sysbll.h"

namespace Ui {
class SysWindow;
}

class SysWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SysWindow(QWidget *parent = nullptr);

    ~SysWindow();

protected:
    void mouseReleaseEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_MinB_clicked();

    void on_CloseB_clicked();

    void on_FinshB_clicked();

    void on_AddB_clicked();

    void on_SearhB_clicked();

    void on_ModfiyB_clicked();

    void on_DeleteB_clicked();

    void on_MgrRb_clicked();

    void on_SysInfoRb_clicked();

    void on_InfoT_returnPressed();

private:
    bool isPressedWidget;
    QPoint m_lastPos;
    Ui::SysWindow *ui;
    enum Status
    {
        MgrSta=0x01,
        SysSta=0x02
    }sta;
    enum FinshModel
    {
        Add=0x01,
        Search=0x02,
        Modfiy=0x03,
        Delete=0x04,
    }finshModel;
    enum AddInfoStatus
    {
        MgrIdSta=0x01,
        NameSta=0x02,
        TeleSta=0x03,
        FIdSta=0x04,
        ExitSta=0x05
    }addInfoSta;

    void setSta();
};

#endif // SYSWINDOW_H
