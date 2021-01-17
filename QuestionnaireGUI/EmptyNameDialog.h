#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_EmptyNameDialog.h"


class EmptyNameDialog :public QDialog
{
    Q_OBJECT

public:
    EmptyNameDialog(QWidget* parent = nullptr);
private:
    Ui::EmptyNameDialog ui;
};
