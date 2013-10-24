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
    delete ui;
}




// SLOT
void MainWindow::on_pathLineEdit_returnPressed()
{
    on_confirmPathButton_clicked();
}

void MainWindow::on_confirmPathButton_clicked()
{
    bitmap  = new Bitmap(ui->pathLineEdit->text().toStdString().c_str());
}

void MainWindow::on_okTestButton_clicked()
{

}

void MainWindow::on_koTestButton_clicked()
{

}

