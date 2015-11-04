#include "mainwindow.h"
#include <QApplication>
#include <QTcpSocket>
#include <QHostAddress>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QTcpSocket as;
    QString addrstring("172.17.13.59");
    QHostAddress addr(addrstring);
    as.connectToHost(addr,1234);
    as.write("Need A Table");
    as.waitForReadyRead(3000);
    QString str = as.readAll();
    std::cout<<str.toStdString()<<std::endl;



    return a.exec();
}
