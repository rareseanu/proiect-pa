#pragma once
#include <QMainWindow>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StartWindow; }
QT_END_NAMESPACE

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow(QMainWindow* source,QWidget *parent = nullptr);
    void StartQuiz();
private:
    Ui::StartWindow ui;
    QMainWindow* source;
};
