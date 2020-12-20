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


void SecDialog::on_pushButton_3_clicked()
{
    int verificare2 = 0;
        if(ui->checkBox->isChecked())
        {
            verificare2++;
        }
        if(ui->checkBox_2->isChecked())
        {
            verificare2++;
        }
        if(ui->checkBox_3->isChecked())
        {
            if(verificare2 > 0)
            {
                verificare2--;
            }
        }
        if(ui->checkBox_4->isChecked())
        {
            if(verificare2 > 0)
            {
                verificare2--;
            }
        }
        if(verificare2 == 0)
        {
            QMessageBox::about(this,"Verificare", "Raspuns gresit");
        }
        else
        {
            if(verificare2 == 2)
            {
                QMessageBox::about(this,"Verificare", "Raspuns corect");
            }
            else
            {
                QMessageBox::about(this,"Verificare", "Raspuns partial corect");
            }
        }
}
