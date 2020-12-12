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


void MainWindow::on_pushButton_clicked()
{
    hide();
    secDialog = new SecDialog(this);
    secDialog->show();
}

void MainWindow::on_radioButton_clicked()
{
    QMessageBox::about(this,"Verificare", "Raspuns corect");
}

void MainWindow::on_radioButton_2_clicked()
{
  QMessageBox::about(this,"Verificare", "Raspuns gresit");
}

void MainWindow::on_radioButton_3_clicked()
{
    QMessageBox::about(this,"Verificare", "Raspuns gresit");
}

void MainWindow::on_radioButton_4_clicked()
{
    QMessageBox::about(this,"Verificare", "Raspuns gresit");
}
