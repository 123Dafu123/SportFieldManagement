#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QMainWindow>
#include "sysadminwindow.h"

namespace Ui {
class LogWindow;
}

class LogWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget *parent = nullptr);
    ~LogWindow();

private:
    Ui::LogWindow *ui;
    SysAdminWindow sysAdmin;

    void log();
};

#endif // LOGWINDOW_H
