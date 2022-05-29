#include <QObject>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QTableView>
#include "logform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LogForm log;
    log.show();

    return a.exec();
}
