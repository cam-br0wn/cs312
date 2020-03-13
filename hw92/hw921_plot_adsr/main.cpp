/***************************************************************
 main.cpp
 Copyright (c) Carleton College CS312 free open source
 Assignment: hw922
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc@carleton.edu
 DATE: 2020-03-10
 TIME: 13:13:46
 ****************************************************************/

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
