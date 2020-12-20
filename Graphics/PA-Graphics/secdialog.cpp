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

void SecDialog::on_radioButton_clicked()
{
    QMessageBox::about(this,"Verificare", "Raspuns gresit");
}

void SecDialog::on_radioButton_2_clicked()
{
    QMessageBox::about(this,"Verificare", "Raspuns corect");
}

void SecDialog::on_radioButton_3_clicked()
{
    QMessageBox::about(this,"Verificare", "Raspuns gresit");
}

void SecDialog::on_radioButton_4_clicked()
{
    QMessageBox::about(this,"Verificare", "Raspuns gresit");
}
