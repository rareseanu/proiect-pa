#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QuestionForm.h"
#include "FinishDialog.h"
#include "StartWindow.h"


class QuestionWindow : public QMainWindow
{
    Q_OBJECT

public:
    QuestionWindow(QWidget* parent = nullptr);
    void OpenDialog();
    Ui::QuestionWindow GetUi();
private:
    Ui::QuestionWindow ui;
    FinishDialog finishDialog;
    StartWindow startWindow=StartWindow(this);
};
