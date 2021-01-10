#include "SendDialog.h"
#include "ui_SendDialog.h"

SendDialog::SendDialog(QWidget *parent)
{
    ui.setupUi(this);
    QObject::connect(ui.pushButton, &QPushButton::clicked, this, &QDialog::close);
}

Ui::SendDialog SendDialog::GetUi()
{
    return ui;
}
