#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_HelpDialog.h"


class HelpDialog :public QDialog
{
    Q_OBJECT

public:
   HelpDialog(QWidget* parent = nullptr);
private:
    Ui::HelpDialog ui;
};
