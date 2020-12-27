#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_FinishDialog.h"
    

class FinishDialog:public QDialog
{
    Q_OBJECT

public:
    FinishDialog(QWidget* parent = nullptr);
private:
    Ui::FinishDialog ui;
};

