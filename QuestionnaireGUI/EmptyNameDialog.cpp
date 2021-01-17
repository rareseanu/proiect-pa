#include "EmptyNameDialog.h"
#include "ui_EmptyNameDialog.h"

EmptyNameDialog::EmptyNameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmptyNameDialog)
{
    ui->setupUi(this);
}

EmptyNameDialog::~EmptyNameDialog()
{
    delete ui;
}
