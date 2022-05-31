#ifndef MBRWINDOW_H
#define MBRWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>
#include "BLL/mbrbll.h"

namespace Ui {
class MbrWindow;
}

class MbrWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MbrWindow(QWidget *parent = nullptr);
    ~MbrWindow();

protected:
    void mouseReleaseEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_CloseB_clicked();

    void on_MinB_clicked();


    void on_FeildRb_clicked();

    void on_MbrInfoRb_clicked();

    void on_RechargeB_clicked();

    void on_RechargeFinshB_clicked();

    void on_SearchB_clicked();

    void on_OrderB_clicked();

    void on_OrderEndB_clicked();

    void on_SearchT_returnPressed();

    void on_RechargeT_returnPressed();

private:
    bool isPressedWidget;
    QPoint m_lastPos;
    Ui::MbrWindow *ui;
    enum Status
    {
        MbrInfoSta=0x01,
        FeildSta=0x02
    }sta;

    void setStatus();
};

#endif // MBRWINDOW_H
