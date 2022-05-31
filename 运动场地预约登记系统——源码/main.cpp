#include <QApplication>
#include <QThread>
#include "Ui/logform.h"
#include "DAL/dbconnection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBConnection::getConnection();
    LogForm log;
    log.show();
    return a.exec();
}
