#include "SendDialog.h"
#include "ui_SendDialog.h"

SendDialog::SendDialog(QWidget *parent)
{
    ui.setupUi(this);
}

Ui::SendDialog SendDialog::GetUi()
{
    return ui;
}
