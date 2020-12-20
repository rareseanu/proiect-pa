#include "secdialog.h"
#include "ui_secdialog.h"
#include <QMessageBox>

 MainWindow *mainWindow;
 ThirdDialog * thirdDialog;
SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButton_clicked()
{
    hide();
    thirdDialog = new ThirdDialog(this);
    thirdDialog->show();
}

void SecDialog::on_pushButton_2_clicked()
{
     hide();
     mainWindow = new MainWindow(this);
     mainWindow->show();
}

int verificare2 = 0;

void SecDialog::on_radioButton_clicked()
{
    verificare2 = 1;
}

void SecDialog::on_radioButton_2_clicked()
{
    verificare2 = 2;
}

void SecDialog::on_radioButton_3_clicked()
{
    verificare2 = 3;
}

void SecDialog::on_radioButton_4_clicked()
{
    verificare2 = 4;
}

void SecDialog::on_pushButton_3_clicked()
{
    if(verificare2 == 3)
    {
        QMessageBox::about(this,"Verificare", "Raspuns corect");
    }
    else
    {
          QMessageBox::about(this,"Verificare", "Raspuns gresit");
    }
}
