#include "thirddialog.h"
#include "ui_thirddialog.h"
#include <QMessageBox>

SecDialog *secDialog2;
ThirdDialog::ThirdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdDialog)
{
    ui->setupUi(this);
}

ThirdDialog::~ThirdDialog()
{
    delete ui;
}


void ThirdDialog::on_pushButton_clicked()
{
    hide();
    secDialog2 = new SecDialog(this);
    secDialog2->show();
}

void ThirdDialog::on_pushButton_2_clicked()
{
    hide();
}

void ThirdDialog::on_radioButton_clicked()
{
   QMessageBox::about(this,"Verificare", "Raspuns gresit");
}

void ThirdDialog::on_radioButton_2_clicked()
{
   QMessageBox::about(this,"Verificare", "Raspuns gresit");
}

void ThirdDialog::on_radioButton_3_clicked()
{
    QMessageBox::about(this,"Verificare", "Raspuns corect");
}

void ThirdDialog::on_radioButton_4_clicked()
{
    QMessageBox::about(this,"Verificare", "Raspuns gresit");
}
