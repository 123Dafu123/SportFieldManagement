#ifndef REGFORM_H
#define REGFORM_H

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include "BLL/regbll.h"


namespace Ui {
class RegForm;
}

class RegForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegForm(QWidget *parent = nullptr);
    ~RegForm();

protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_CloseB_clicked();

    void on_MinB_clicked();

    void on_Reg_clicked();

    void on_Cancel_clicked();

    void on_IdT_returnPressed();

    void on_PswdT_returnPressed();

    void on_NameT_returnPressed();

    void on_TeleT_returnPressed();

private:
    bool isPressedWidget;
    QPoint m_lastPos;
    Ui::RegForm *ui;

    void reg();
};

#endif // REGFORM_H
