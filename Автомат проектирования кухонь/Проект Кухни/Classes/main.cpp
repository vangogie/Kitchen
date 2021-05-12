#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>//для русского языка

int main(int argc, char *argv[])
{
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("iKitchen");
    w.setFixedSize(1100,650);
    w.show();
    return a.exec();
}
