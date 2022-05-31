#ifndef MGRWINDOW_H
#define MGRWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>
#include "BLL/mgrbll.h"

namespace Ui {
class MgrWindow;
}

class MgrWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MgrWindow(QWidget *parent = nullptr);
    ~MgrWindow();

protected:
    void mouseReleaseEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_MinB_clicked();

    void on_CloseB_clicked();

    void on_FeildRb_clicked();

    void on_MgrInfoRb_clicked();

    void on_AddB_clicked();

    void on_SearhB_clicked();

    void on_StatisticB_clicked();

    void on_ModfiyB_clicked();

    void on_DeleteB_clicked();

    void on_FinshB_clicked();

    void on_InfoT_returnPressed();

private:
    bool isPressedWidget;
    QPoint m_lastPos;
    Ui::MgrWindow *ui;
    enum Status
    {
        FeildSta=0x01,
        MgrInfoSta=0x02,
    }sta;
    enum FinshModel
    {
        Add=0x01,
        Search=0x02,
        Statistic=0x03,
        Modfiy=0x04,
        Delete=0x05,
    }finshModel;
    enum AddInfoStatus
    {
        IdSta=0x01,
        NameSta=0x02,
        TypeSta=0x03,
        AddrSta=0x04,
        FeeSta=0x05,
        ExitSta=0x06,
    }addInfoSta;

    void setSta();
};

#endif // MGRWINDOW_H
