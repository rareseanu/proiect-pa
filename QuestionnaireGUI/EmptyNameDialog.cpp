#include "EmptyNameDialog.h"

EmptyNameDialog::EmptyNameDialog(QWidget* parent) {
	ui.setupUi(this);

	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &QDialog::accept);
}