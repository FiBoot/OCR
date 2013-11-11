#include <iostream>
#include <fstream>
#include <stack>
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


void MainWindow::process()
{
    std::string filepath(ui->pathLineEdit->text().toStdString());
    Bitmap *bitmap  = new Bitmap(filepath.c_str());



    if (bitmap->isValid)
    {
        QPixmap *pixmap = new QPixmap(filepath.c_str());
        ui->image1Label->setPixmap(*pixmap);

        std::stack<bool> stack = bitmap->negative();

        pixmap = new QPixmap(bitmap->getTmpfilepath());
        ui->image2Label->setPixmap(*pixmap);

        while (!stack.empty())
        {
            std::cout << stack.top() << std::endl;
            stack.pop();
        }

        delete bitmap;
    }
}


// SLOT
void MainWindow::on_pathLineEdit_returnPressed()
{
    process();
}

void MainWindow::on_confirmPathButton_clicked()
{
    process();
}

void MainWindow::on_okTestButton_clicked()
{

}

void MainWindow::on_koTestButton_clicked()
{

}

