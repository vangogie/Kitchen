#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCodec>//для русского языка
#include <QMessageBox>//для всплывающего окна
///////////////////////////
#include "iKitchen.h"
#include "MaterialBASE.h"
#include "TempBASE.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //инициализация переменных
    iKitchen QKitchen;//создание кухни
    MaterialBASE iBase;//инициализация базы данных
    int BaseSize = 0;
    TempBASE DSPBase; //инициализация базы ДСП любой толщины
    TempBASE MDFBase; //инициализация базы МДФ любой толщины
    TempBASE HDFBase; //инициализация базы ХДФ любой толщины
    TempBASE FurnitureBase; //инициализация базы петель
    TempBASE FixBase; //инициализация базы конфирматов
    TempBASE TortsBase; //инициализация базы торцовок любой толщины
    TempBASE FasadCoverBase; //инициализация базы покрытия фасадов
    TempBASE LegsBase; //инициализация базы ножек

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_OK_clicked();

    void on_comboBox_ClassModule_currentIndexChanged(const QString &arg1);

    void on_Calculate_clicked();

    void on_Change_Material_clicked();

    void on_Pay_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
