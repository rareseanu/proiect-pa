#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_usename->text();
    QString password = ui->lineEdit_password->text();

    if(username == "test" && password == "test")
    {
        QMessageBox::information(this,"Login", "Username & Password are correct");
    }
    else
    {
        QMessageBox::information(this,"Login", "Username or Password are not correct");
    }
}
