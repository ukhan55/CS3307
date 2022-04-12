//Author: Usman Khan
//Date: 10-5-2021
//This is the main class that will run the GUI

#include "maingui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainGui w;
    w.show();
    return a.exec();
}
