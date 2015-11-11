#include "weplaygames.h"
#include <QApplication>
#include <windowtools.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WePlayGames w;
    w.show();

    return a.exec();
}
