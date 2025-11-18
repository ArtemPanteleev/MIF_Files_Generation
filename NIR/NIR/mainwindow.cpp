#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int NUMBER = Settings::instanse()->getNUMBER();
    int NUMBER_2 = Settings::instanse()->getNUMBER_2();
    int MIN = Settings::instanse()->getMIN();
    int MAX = Settings::instanse()->getMAX();
    ui->NUMBER->setText(QString::number(NUMBER));
    ui->NUMBER_2->setText(QString::number(NUMBER_2));
    ui->MIN_RADIX->setText(QString::number(MIN));
    ui->MAX_RADIX->setText(QString::number(MAX));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete parser;
}

void MainWindow::on_OPEN_ALL_clicked()
{
    name = QFileDialog::getOpenFileName(this);
    ui->OPEN->setText(name);
    ui->INFORMATION->setText(QString("Открыт файл ") + name);
}

void MainWindow::on_APPLY_clicked()
{
    QString WIDTH = ui->BIT->text();
    Settings::instanse()->setWIDTH(stoi(WIDTH.toStdString()));
    QString DEPTH = ui->RADIX->text();
    Settings::instanse()->setDEPTH(stoi(DEPTH.toStdString()));

    if(ui->ADDRES_BIN->isChecked())
    {
        Settings::instanse()->setADDRESS_RADIX("BIN");
    }
    else if(ui->ADDRES_OCT->isChecked())
    {
        Settings::instanse()->setADDRESS_RADIX("OCT");
    }
    else if(ui->ADDRES_DEC->isChecked())
    {
        Settings::instanse()->setADDRESS_RADIX("UNS");
    }
    else if(ui->ADDRES_HEX->isChecked())
    {
        Settings::instanse()->setADDRESS_RADIX("HEX");
    }

    if(ui->DATA_BIN->isChecked())
    {
        Settings::instanse()->setDATA_RADIX("BIN");
    }
    else if(ui->DATA_OCT->isChecked())
    {
        Settings::instanse()->setDATA_RADIX("OCT");
    }
    else if(ui->DATA_DEC->isChecked())
    {
        Settings::instanse()->setDATA_RADIX("UNS");
    }
    else if(ui->DATA_HEX->isChecked())
    {
        Settings::instanse()->setDATA_RADIX("HEX");
    }
    ui->INFORMATION->setText(QString("Всё настроено"));
}

void MainWindow::on_GET_GENERATION_clicked()
{
    QString NUMBER = ui->NUMBER->text();
    Settings::instanse()->setNUMBER(stoi(NUMBER.toStdString()));
    QString NUMBER_2 = ui->NUMBER_2->text();
    Settings::instanse()->setNUMBER_2(std::pow(10, stoi(NUMBER_2.toStdString())));
    QString MIN = ui->MIN_RADIX->text();
    Settings::instanse()->setMIN(stoi(MIN.toStdString()));
    QString MAX = ui->MAX_RADIX->text();
    Settings::instanse()->setMAX(stoi(MAX.toStdString()));
    if(ui->ADDITION->isChecked())
    {
        Settings::instanse()->setOPERATION("ADDITION");
    }
    else if(ui->SUBTRACTION->isChecked())
    {
        Settings::instanse()->setOPERATION("SUBTRACTION");
    }
    else if(ui->MULTIPLICATION->isChecked())
    {
        Settings::instanse()->setOPERATION("MULTIPLICATION");
    }
    else if(ui->DIVISION->isChecked())
    {
        Settings::instanse()->setOPERATION("DIVISION");
    }
    else if(ui->DEGREE->isChecked())
    {
        Settings::instanse()->setOPERATION("DEGREE");
    }
    else if(ui->RADICAL->isChecked())
    {
        Settings::instanse()->setOPERATION("RADICAL");
    }
    else if(ui->COSINE->isChecked())
    {
        Settings::instanse()->setOPERATION("COSINE");
    }
    else if(ui->SINUS->isChecked())
    {
        Settings::instanse()->setOPERATION("SINUS");
    }
    else if(ui->ZERO->isChecked())
    {
        Settings::instanse()->setOPERATION("ZERO");
    }
    parser->Generate(name_generate.toStdString());
    ui->INFORMATION_GENERATION->setText(QString("Файл сгенерирован в ") + name_generate);
}

void MainWindow::on_SAVE_ALL_clicked()
{
    name2 = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Mif (*.mif)"));
    ui->SAVE->setText(name2);
    ui->INFORMATION->setText(QString("Файл будет сохранен в ") + name2);
}

void MainWindow::on_GET_clicked()
{
    if(ui->START_BIN->isChecked())
    {
        Settings::instanse()->setDATA_RADIX_START("BIN");
    }
    else if(ui->START_OCT->isChecked())
    {
        Settings::instanse()->setDATA_RADIX_START("OCT");
    }
    else if(ui->START_DEC->isChecked())
    {
        Settings::instanse()->setDATA_RADIX_START("UNS");
    }
    else if(ui->START_HEX->isChecked())
    {
        Settings::instanse()->setDATA_RADIX_START("HEX");
    }
    QString open = ui->OPEN->text();
    QString save = ui->SAVE->text();
    parser = new File(open.toStdString(), save.toStdString());
    ui->INFORMATION->setText(QString("Файл получен ") + save);
}

void MainWindow::on_APPLY_GENERATION_clicked()
{
    QString WIDTH_GENERATE = ui->BIT_GENERATION->text();
    Settings::instanse()->setWIDTH_GENERATE(stoi(WIDTH_GENERATE.toStdString()));
    QString DEPTH_GENERATE = ui->RADIX_GENERATION->text();
    Settings::instanse()->setDEPTH_GENERATE(stoi(DEPTH_GENERATE.toStdString()));

    if(ui->ADDRES_GENERATION_BIN->isChecked())
    {
        Settings::instanse()->setADDRESS_RADIX_GENERATE("BIN");
    }
    else if(ui->ADDRES_GENERATION_OCT->isChecked())
    {
        Settings::instanse()->setADDRESS_RADIX_GENERATE("OCT");
    }
    else if(ui->ADDRES_GENERATION_DEC->isChecked())
    {
        Settings::instanse()->setADDRESS_RADIX_GENERATE("UNS");
    }
    else if(ui->ADDRES_GENERATION_HEX->isChecked())
    {
        Settings::instanse()->setADDRESS_RADIX_GENERATE("HEX");
    }

    if(ui->DATA_GENERATION_BIN->isChecked())
    {
        Settings::instanse()->setDATA_RADIX_GENERATE("BIN");
    }
    else if(ui->DATA_GENERATION_OCT->isChecked())
    {
        Settings::instanse()->setDATA_RADIX_GENERATE("OCT");
    }
    else if(ui->DATA_GENERATION_DEC->isChecked())
    {
        Settings::instanse()->setDATA_RADIX_GENERATE("UNS");
    }
    else if(ui->DATA_GENERATION_HEX->isChecked())
    {
        Settings::instanse()->setDATA_RADIX_GENERATE("HEX");
    }
    ui->INFORMATION_GENERATION->setText(QString("Всё настроено"));
}

void MainWindow::on_SAVE_GENERATION_ALL_clicked()
{
    name_generate = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Mif (*.mif)"));
    ui->SAVE_GENERATION->setText(name_generate);
    ui->INFORMATION_GENERATION->setText(QString("Файл будет сгенерирован в ") + name_generate);
}
