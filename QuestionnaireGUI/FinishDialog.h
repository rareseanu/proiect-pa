#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_FinishDialog.h"
#include "SendDialog.h"
    

class FinishDialog:public QDialog
{
    Q_OBJECT

public:
    FinishDialog(QWidget* parent = nullptr);
    void onOkButtonClicked();
private:
    Ui::FinishDialog ui;
    SendDialog* sendDialog;
};

