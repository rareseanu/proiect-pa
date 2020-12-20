#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

SecDialog *secDialog;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int verificare = 0;

void MainWindow::on_pushButton_clicked()
{
    hide();
    secDialog = new SecDialog(this);
    secDialog->show();
}

void MainWindow::on_radioButton_clicked()
{
    verificare = 1;
}

void MainWindow::on_radioButton_2_clicked()
{
    verificare = 2;
}

void MainWindow::on_radioButton_3_clicked()
{
    verificare = 3;
}

void MainWindow::on_radioButton_4_clicked()
{
    verificare = 4;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(verificare == 1)
    {
        QMessageBox::about(this,"Verificare", "Raspuns corect");
    }
    else
    {
          QMessageBox::about(this,"Verificare", "Raspuns gresit");
    }
}
