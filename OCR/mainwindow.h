#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bitmap.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void process();


private slots:
    void on_pathLineEdit_returnPressed();
    void on_confirmPathButton_clicked();
    void on_okTestButton_clicked();
    void on_koTestButton_clicked();


private:
    Ui::MainWindow  *ui;
};

#endif // MAINWINDOW_H
