#include "FinishDialog.h"

FinishDialog::FinishDialog(QWidget* parent) {
	ui.setupUi(this);
}

void FinishDialog::onOkButtonClicked()
{
    sendDialog = new SendDialog(this);
    sendDialog->show();
}