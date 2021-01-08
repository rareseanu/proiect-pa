#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QuestionForm.h"
#include "FinishDialog.h"
#include "StartWindow.h"
#include "SendDialog.h"

class QuestionWindow : public QMainWindow
{
    Q_OBJECT

public:
    QuestionWindow(QWidget* parent = nullptr);
    void OpenDialog();
    void on_btnClose_clicked();
    void on_focusLoss();
    Ui::QuestionWindow GetUi();
 
private:
    Ui::QuestionWindow ui;
    FinishDialog finishDialog;
    StartWindow startWindow=StartWindow(this);
    SendDialog sendDialog;
};
