#include "janelalogin.h"
#include <QSqlQuery>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    janelaLogin w;
    w.show();
    return a.exec();
}
