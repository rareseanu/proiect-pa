#ifndef FRAUDDIALOG_H
#define FRAUDDIALOG_H

#include <QDialog>
#include "ui_FraudDialog.h"

class FraudDialog : public QDialog
{
    Q_OBJECT

public:
    FraudDialog(QWidget *parent = nullptr);

private:
    Ui::FraudDialog ui;
};

#endif // FRAUDDIALOG_H
