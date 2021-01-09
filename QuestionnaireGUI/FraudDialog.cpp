#include "FraudDialog.h"
#include "ui_FraudDialog.h"

FraudDialog::FraudDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FraudDialog)
{
    ui->setupUi(this);
}

FraudDialog::~FraudDialog()
{
    delete ui;
}
