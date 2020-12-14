#include "mainwindow.h"
#include <QtWidgets/QMessageBox>

StartWindow::StartWindow(QMainWindow* source,QWidget *parent)
    : QMainWindow(parent),source(source)
{
    ui.setupUi(this); 
    connect(ui.startQuizButton, &QPushButton::pressed, this, &StartWindow::StartQuiz);
}

void StartWindow::StartQuiz() {
    source->show();
    close();
}