#include "FraudDialog.h"
#include "ui_FraudDialog.h"

FraudDialog::FraudDialog(QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
    QObject::connect(ui.pushButton, &QPushButton::clicked, this, &QDialog::accept);
}
