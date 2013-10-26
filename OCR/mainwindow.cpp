#include <fstream>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete bitmap;
    delete ui;
}


// SLOT
void MainWindow::on_pathLineEdit_returnPressed()
{
    on_confirmPathButton_clicked();
}

void MainWindow::on_confirmPathButton_clicked()
{
    std::string filepath(ui->pathLineEdit->text().toStdString());

    bitmap  = new Bitmap(filepath.c_str());
    if (bitmap->isValid)
    {
        QPixmap *pixmap = new QPixmap(filepath.c_str());
        ui->image1Label->setPixmap(*pixmap);

        bitmap->negative();

        pixmap = new QPixmap(bitmap->getTmpfilepath());
        ui->image2Label->setPixmap(*pixmap);
    }
}

void MainWindow::on_okTestButton_clicked()
{

}

void MainWindow::on_koTestButton_clicked()
{

}

