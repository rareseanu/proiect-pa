#pragma once
#include "ui_SendDialog.h"
#include <QDialog>

class SendDialog : public QDialog
{
    Q_OBJECT

public:
    SendDialog(QWidget *parent = nullptr);
    Ui::SendDialog GetUi();
private:
    Ui::SendDialog ui;
};