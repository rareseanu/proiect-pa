#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_StartWindow.h"
#include "EmptyNameDialog.h"

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow(QMainWindow* source,QWidget *parent = nullptr);
    void StartQuiz();
private:
    Ui::StartWindow ui;
    EmptyNameDialog emptyNameDialog;
    QMainWindow* source;
};
