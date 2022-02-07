#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <crc32.h>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile f("/home/dima/Program/mstar-bin-tool-master/MstarUpgrade.bin");
    if (!f.open(QIODevice::ReadWrite))
            return;
    QByteArray b;
    b=f.readAll();
    f.close();
    b.insert(176,48);
    char* c=b.data();
    char* v=c+176;
    *v=48;
    v++;
    *v=52;
    b.remove(237,1);
    char* v1=c+237;
    *v1=56;
    char* v2=c+265;
    *v2=49;


    Crc32 CRC;
    QByteArray ba;
    ba.append(c,16384);
    quint32 crc=CRC.calculateFromQByteArray(ba);

    char* v3=c+653672456;
    *v3=59;
    v3++;
    *v3=155;
    v3++;
    *v3=127;
    v3++;
    *v3=169;



    QFile f1("/home/dima/Program/mstar-bin-tool-master/MstarUpgrade1.bin");
    if (!f1.open(QIODevice::ReadWrite))
            return;
    f1.write(c,b.size());
    f1.close();



//    QFile f1("/home/dima/Program/mstar-bin-tool-master/MstarUpgrade.bin");
//    if (!f1.open(QIODevice::ReadWrite))
//            return;
//    QFile f2("/home/dima/Program/mstar-bin-tool-master/MstarUpgrade1.bin");
//    if (!f2.open(QIODevice::ReadWrite))
//            return;
//    while (!f1.atEnd()) {
//        char c1;
//        f1.read(&c1,1);
//        char c2;
//        f2.read(&c2,1);
//        if(c1!=c2)
//        {
//            qDebug() << f1.pos() << "    " << c1 << "    " << c2 << "    " ;
//        }
//    }

//    f1.close();
//    f2.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
