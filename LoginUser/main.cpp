
#include <QApplication>
#include "Game.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
/*
Tutorial Topics:
-parents
-QGraphicsTextItem, setPlainText(), setFont(),setDefaultTextColor()
*/
MainWindow * mainwindow;


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    mainwindow = new MainWindow();
    mainwindow ->show();



    return a.exec();
}
