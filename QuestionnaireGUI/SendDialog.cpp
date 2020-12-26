#include "SendDialog.h"
#include "ui_SendDialog.h"

SendDialog::SendDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendDialog)
{
    ui->setupUi(this);
}

SendDialog::~SendDialog()
{
    delete ui;
}
