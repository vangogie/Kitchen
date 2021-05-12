#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    iBase.FromLibrary();//считываем из библиотеки данные
    BaseSize = iBase.GetSize();//определяем количество элементов в базе
    //Выпадающий список для элементов в Базе
    QStringList DSPElements;
    QStringList MDFElements;
    QStringList HDFElements;
    QStringList FurnitureElements;
    QStringList FixElements;
    QStringList FasadCoverElements;
    QStringList TortsElements;
    QStringList LegElements;

    //распределение всех элементов по типу
    for(int i = 0; i<BaseSize; i++)
    {
       if(iBase.isDSP(i))
        {
            QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//локализация русского языка
            QString text1 = QString::fromLocal8Bit(iBase.GetMaterial(i).c_str());
            double costing = iBase.GetCosting(i);
            double QTY = iBase.GetQTY(i);
            DSPElements.push_back(text1);
            DSPBase.AddTempMaterial(iBase.TakeMaterial(i), QTY, costing);//добавляем в базу материалов ДСП материал
        }
       else if(iBase.isMDF(i))
       {
           QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//локализация русского языка
           QString text1 = QString::fromLocal8Bit(iBase.GetMaterial(i).c_str());
           double costing = iBase.GetCosting(i);
           double QTY = iBase.GetQTY(i);
           MDFElements.push_back(text1);
           MDFBase.AddTempMaterial(iBase.TakeMaterial(i), QTY, costing);//добавляем в базу материалов ДСП материал
       }
       else if(iBase.isHDF(i))
       {
           QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//локализация русского языка
           QString text1 = QString::fromLocal8Bit(iBase.GetMaterial(i).c_str());
           double costing = iBase.GetCosting(i);
           double QTY = iBase.GetQTY(i);
           HDFElements.push_back(text1);
           HDFBase.AddTempMaterial(iBase.TakeMaterial(i), QTY, costing);//добавляем в базу материалов ДСП материал
       }
       else if(iBase.isFurniture(i))
       {
           QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//локализация русского языка
           QString text1 = QString::fromLocal8Bit(iBase.GetMaterial(i).c_str());
           double costing = iBase.GetCosting(i);
           double QTY = iBase.GetQTY(i);
           FurnitureElements.push_back(text1);
           FurnitureBase.AddTempMaterial(iBase.TakeMaterial(i), QTY, costing);//добавляем в базу материалов ДСП материал
       }
       else if(iBase.isFix(i))
       {
           QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//локализация русского языка
           QString text1 = QString::fromLocal8Bit(iBase.GetMaterial(i).c_str());
           double costing = iBase.GetCosting(i);
           double QTY = iBase.GetQTY(i);
           FixElements.push_back(text1);
           FixBase.AddTempMaterial(iBase.TakeMaterial(i), QTY, costing);//добавляем в базу материалов ДСП материал
       }
       else if(iBase.isFasadCover(i))
       {
           QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//локализация русского языка
           QString text1 = QString::fromLocal8Bit(iBase.GetMaterial(i).c_str());
           double costing = iBase.GetCosting(i);
           double QTY = iBase.GetQTY(i);
           FasadCoverElements.push_back(text1);
           FasadCoverBase.AddTempMaterial(iBase.TakeMaterial(i), QTY, costing);//добавляем в базу материалов ДСП материал
       }
       else if(iBase.isTorts(i))
       {
           QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//локализация русского языка
           QString text1 = QString::fromLocal8Bit(iBase.GetMaterial(i).c_str());
           double costing = iBase.GetCosting(i);
           double QTY = iBase.GetQTY(i);
           TortsElements.push_back(text1);
           TortsBase.AddTempMaterial(iBase.TakeMaterial(i), QTY, costing);//добавляем в базу материалов ДСП материал
       }
       else if(iBase.isLeg(i))
       {
           QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//локализация русского языка
           QString text1 = QString::fromLocal8Bit(iBase.GetMaterial(i).c_str());
           double costing = iBase.GetCosting(i);
           double QTY = iBase.GetQTY(i);
           LegElements.push_back(text1);
           LegsBase.AddTempMaterial(iBase.TakeMaterial(i), QTY, costing);//добавляем в базу материалов ДСП материал
       }
    }
    //присвоение значений в выпадающий список
    ui->comboBox_DSPBase->addItems(DSPElements);
    ui->comboBox_MDFBase->addItems(MDFElements);
    ui->comboBox_HDFBase->addItems(HDFElements);
    ui->comboBox_FurnitureBase->addItems(FurnitureElements);
    ui->comboBox_FixBase->addItems(FixElements);
    ui->comboBox_FasadCoverBase->addItems(FasadCoverElements);
    ui->comboBox_TortsBase->addItems(TortsElements);
    ui->comboBox_LegsBase->addItems(LegElements);

    //Выпадающий список для выбора тумбочки или шкафчика
    QStringList ClassModule;
    ClassModule.push_back("Тумбочка");
    ClassModule.push_back("Шкафчик");
    ui->comboBox_ClassModule->addItems(ClassModule);

    //Выпадающий список для выбора конфигурации шкафчика:
    QStringList ModuleType;
    ModuleType.push_back("Без полок");
    ModuleType.push_back("Одна полка");
    ModuleType.push_back("Две полки");
    ModuleType.push_back("Две полки и две дверцы");
    ui->comboBox_ModuleType->addItems(ModuleType);

    //Выпадающий список для выбора конфигурации тумбочек:
    QStringList CabinetType;
    CabinetType.push_back("Одна полка");
    CabinetType.push_back("Одна полка и две дверцы");
    CabinetType.push_back("Две полки");
    CabinetType.push_back("Две полки и две дверцы");
    ui->comboBox_CabinetType->addItems(CabinetType);


    //Выпадающий список для выбора радиуса скругления фасадов:
    QStringList RadiusSet;
    RadiusSet.push_back("Радиус 1 мм");
    RadiusSet.push_back("Радиус 2 мм");
    RadiusSet.push_back("Радиус 3 мм");
    RadiusSet.push_back("Радиус 4 мм");
    RadiusSet.push_back("Радиус 5 мм");
    RadiusSet.push_back("Радиус 6 мм");
    ui->comboBox_Radius->addItems(RadiusSet);


    //скрываем поля нашей кухни
    ui->My_iKitchen->hide();
    ui->iKitchen_text->hide();
    ui->Calculate->hide();
    ui->label_17->hide();
    ui->iKitchen_Calculate->hide();
    ui->Pay->hide();
    ui->label_21->hide();//поле для ввода суммы пользователю
    ui->label_19->hide();//поле для ввода суммы пользователю
    ui->PaySumm->hide();//поле для ввода суммы пользователю
    ui->label_20->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OK_clicked()
{
    double H = ui->Height->toPlainText().toDouble();//вытягиваем высоту, которую ввел пользователь
    double W = ui->Width->toPlainText().toDouble();//вытягиваем ширину, которую ввел пользователь
    double Dp = ui->Depth->toPlainText().toDouble();//вытягиваем глубину, которую ввел пользователь

    /*
    QString H2 = QString::number(H);//перевод из double в Qstring
    QString W2 = QString::number(W);//перевод из double в Qstring
    QString Dp2 = QString::number(Dp);//перевод из double в Qstring
    ui->HH->setText(H2);//вывод в label текста Qstring
    ui->WW->setText(W2);//вывод в label текста Qstring
    ui->DPDP->setText(Dp2);//вывод в label текста Qstring
    */

    int classModule  = 1;
    int moduleType = 1;

    if(ui->comboBox_ClassModule->currentIndex() == 0)
    {
        classModule = 1;
        if(ui->comboBox_CabinetType->currentIndex() == 0) moduleType = 1;
        else if(ui->comboBox_CabinetType->currentIndex() == 1) moduleType = 2;
        else if(ui->comboBox_CabinetType->currentIndex() == 2) moduleType = 3;
        else if(ui->comboBox_CabinetType->currentIndex() == 3) moduleType = 4;
    }
    else if(ui->comboBox_ClassModule->currentIndex() == 1)
    {
        classModule = 2;
        if(ui->comboBox_ModuleType->currentIndex() == 0) moduleType = 1;
        else if(ui->comboBox_ModuleType->currentIndex() == 1) moduleType = 2;
        else if(ui->comboBox_ModuleType->currentIndex() == 2) moduleType = 3;
        else if(ui->comboBox_ModuleType->currentIndex() == 3) moduleType = 4;
    }
    ////////////////////////////////////////////////////////////////////////
    //ВЫБИРАЕМ РАДУС СКРУГЛЕНИЯ ФАСАДОВ
    int radius = 1;
    if(ui->comboBox_Radius->currentIndex() == 0) radius = 1;
    if(ui->comboBox_Radius->currentIndex() == 1) radius = 2;
    if(ui->comboBox_Radius->currentIndex() == 2) radius = 3;
    if(ui->comboBox_Radius->currentIndex() == 3) radius = 4;
    if(ui->comboBox_Radius->currentIndex() == 4) radius = 5;
    if(ui->comboBox_Radius->currentIndex() == 5) radius = 6;
    QKitchen.SetfasadRadius(radius);

    ////////////////////////////////////////////////////////////////////////
    //ВЫБИРАЕМ ДИЗАЙН ФАСАДОВ
    int fasadType = 1;
    if(ui->RadioPractick->isChecked()) fasadType = 1;
    if(ui->RadioClassicModern->isChecked()) fasadType = 2;
    if(ui->RadioClassic->isChecked()) fasadType = 3;
    if(ui->RadioModern->isChecked()) fasadType = 4;
    if(ui->RadioMagnolia->isChecked()) fasadType = 5;
    QKitchen.Setfasadtype(fasadType); //передаем тип фасадов

    ////////////////////////////////////////////////////////////////////////
    //Заносим данные в проект кухни
    QKitchen.SetMatDsp(DSPBase.TakeMaterial(ui->comboBox_DSPBase->currentIndex()));
    QKitchen.SetMatFas(MDFBase.TakeMaterial(ui->comboBox_MDFBase->currentIndex()));
    QKitchen.SetBackWallMaterial(HDFBase.TakeMaterial(ui->comboBox_HDFBase->currentIndex()));
    QKitchen.SetMatFurnit(FurnitureBase.TakeMaterial(ui->comboBox_FurnitureBase->currentIndex()));
    QKitchen.Setfix(FixBase.TakeMaterial(ui->comboBox_FixBase->currentIndex()));
    QKitchen.SetFasPokr(FasadCoverBase.TakeMaterial(ui->comboBox_FasadCoverBase->currentIndex()));
    QKitchen.SetMatTorts(TortsBase.TakeMaterial(ui->comboBox_TortsBase->currentIndex()));
    QKitchen.SetLegs(LegsBase.TakeMaterial(ui->comboBox_LegsBase->currentIndex()));





    QKitchen.GenerateModule(classModule, moduleType, H, W, Dp);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//локализация русского языка
    QString text = QString::fromLocal8Bit(QKitchen.ShowModulesShort().c_str());//для вывода русского языка

    ui->My_iKitchen->show();
    ui->iKitchen_text->show();
    ui->iKitchen_text->setText(text);
    ui->Calculate->show();
    ui->label_17->show();
    ui->iKitchen_Calculate->show();
    ui->Pay->show();
    ui->label_21->show();//поле для ввода суммы пользователю
    ui->label_19->show();//поле для ввода суммы пользователю
    ui->PaySumm->show();//поле для ввода суммы пользователю

    QKitchen.Calculation();
    double allcost = QKitchen.GetAllCost();
    QString strCost = QString::number(allcost, 'f', 2);
    ui->iKitchen_Calculate->setText(strCost);

}

void MainWindow::on_comboBox_ClassModule_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "Тумбочка")
    {
        ui->comboBox_ModuleType->close();
        ui->comboBox_CabinetType->show();
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_14->show();
        ui->label_15->show();
        ui->label_16->show();
    }
    if (arg1 == "Шкафчик")
    {
        ui->comboBox_CabinetType->hide();
        ui->comboBox_ModuleType->show();
        ui->label->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_14->hide();
        ui->label_15->hide();
        ui->label_16->hide();
    }
}

void MainWindow::on_Calculate_clicked()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));//локализация русского языка
    QString text = QString::fromLocal8Bit(QKitchen.Calculation().c_str());//для вывода русского языка
    //ui->iKitchen_Calculate->setText(text);
    QMessageBox msgBox;
    msgBox.setWindowTitle("Расчет стоимости");
    msgBox.setText(text);
    msgBox.exec();
}

void MainWindow::on_Change_Material_clicked()
{
    //ВЫБИРАЕМ РАДУС СКРУГЛЕНИЯ ФАСАДОВ
    int radius = 1;
    if(ui->comboBox_Radius->currentIndex() == 0) radius = 1;
    if(ui->comboBox_Radius->currentIndex() == 1) radius = 2;
    if(ui->comboBox_Radius->currentIndex() == 2) radius = 3;
    if(ui->comboBox_Radius->currentIndex() == 3) radius = 4;
    if(ui->comboBox_Radius->currentIndex() == 4) radius = 5;
    if(ui->comboBox_Radius->currentIndex() == 5) radius = 6;
    QKitchen.SetfasadRadius(radius);

    ////////////////////////////////////////////////////////////////////////
    //ВЫБИРАЕМ ДИЗАЙН ФАСАДОВ
    int fasadType = 1;
    if(ui->RadioPractick->isChecked()) fasadType = 1;
    if(ui->RadioClassicModern->isChecked()) fasadType = 2;
    if(ui->RadioClassic->isChecked()) fasadType = 3;
    if(ui->RadioModern->isChecked()) fasadType = 4;
    if(ui->RadioMagnolia->isChecked()) fasadType = 5;
    QKitchen.Setfasadtype(fasadType); //передаем тип фасадов

    ////////////////////////////////////////////////////////////////////////
    //Заносим данные в проект кухни
    QKitchen.SetMatDsp(DSPBase.TakeMaterial(ui->comboBox_DSPBase->currentIndex()));
    QKitchen.SetMatFas(MDFBase.TakeMaterial(ui->comboBox_MDFBase->currentIndex()));
    QKitchen.SetBackWallMaterial(HDFBase.TakeMaterial(ui->comboBox_HDFBase->currentIndex()));
    QKitchen.SetMatFurnit(FurnitureBase.TakeMaterial(ui->comboBox_FurnitureBase->currentIndex()));
    QKitchen.Setfix(FixBase.TakeMaterial(ui->comboBox_FixBase->currentIndex()));
    QKitchen.SetFasPokr(FasadCoverBase.TakeMaterial(ui->comboBox_FasadCoverBase->currentIndex()));
    QKitchen.SetMatTorts(TortsBase.TakeMaterial(ui->comboBox_TortsBase->currentIndex()));
    QKitchen.SetLegs(LegsBase.TakeMaterial(ui->comboBox_LegsBase->currentIndex()));
}

void MainWindow::on_Pay_clicked()
{
    double cost = ui->PaySumm->toPlainText().toDouble();
    if(cost < QKitchen.GetAllCost())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Не хватает денег");
        QString text = "Введенная сумма меньше необходимой";
        msgBox.setText(text);
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Оплата");
        double delivery = cost - QKitchen.GetAllCost();
        QString text;
        if(QKitchen.intoWork())
        {
            text = "Вы ввели: " + QString::number(cost, 'f', 2) + "грн.\nВаша сдача составляет: "
                    + QString::number(delivery, 'f', 2)+ "грн.\nКухня сгенерирована и отправлена в производство. Хорошего Вам дня!";
            //скрываем поля нашей кухни
            ui->My_iKitchen->hide();
            ui->iKitchen_text->hide();
            ui->Calculate->hide();
            ui->label_17->hide();
            ui->iKitchen_Calculate->hide();
            ui->Pay->hide();
            ui->label_21->hide();//поле для ввода суммы пользователю
            ui->label_20->hide();//поле для ввода суммы пользователю
            ui->label_19->hide();//поле для ввода суммы пользователю
            ui->PaySumm->hide();//поле для ввода суммы пользователю
            iBase.FromLibrary();//считываем из библиотеки данные
        }
        else
        {
            text = QString::fromLocal8Bit(QKitchen.Calculation().c_str());
        }
        msgBox.setText(text);
        msgBox.exec();
    }
}
