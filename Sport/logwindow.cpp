#include "logwindow.h"
#include "ui_logwindow.h"

LogWindow::LogWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogWindow)
{
    ui->setupUi(this);
    connect(ui->p1,&QPushButton::clicked,this,&LogWindow::log);
}

LogWindow::~LogWindow()
{
    delete ui;
}

void LogWindow::log()
{
    this->close();
    sysAdmin.show();
}


