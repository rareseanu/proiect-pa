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

int verificare3 = 0;

void ThirdDialog::on_pushButton_2_clicked()
{
    hide();
}

void ThirdDialog::on_radioButton_clicked()
{
   verificare3 = 1;
}

void ThirdDialog::on_radioButton_2_clicked()
{
   verificare3 = 2;
}

void ThirdDialog::on_radioButton_3_clicked()
{
    verificare3 = 3;
}

void ThirdDialog::on_radioButton_4_clicked()
{
    verificare3 = 4;
}

void ThirdDialog::on_pushButton_3_clicked()
{
    if(verificare3 == 2)
    {
        QMessageBox::about(this,"Verificare", "Raspuns corect");
    }
    else
    {
          QMessageBox::about(this,"Verificare", "Raspuns gresit");
    }
}
