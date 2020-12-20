#include "StartWindow.h"
#include "QuestionWindow.h"
#include <QtWidgets/QMessageBox>

StartWindow::StartWindow(QMainWindow* source,QWidget *parent)
    : QMainWindow(parent),source(source)
{
    ui.setupUi(this); 
    connect(ui.startQuizButton, &QPushButton::pressed, this, &StartWindow::StartQuiz);
    connect(ui.closeButton, &QPushButton::clicked, this, &QMainWindow::close);
}

void StartWindow::StartQuiz() {
    Ui::QuestionWindow sourceUi = dynamic_cast<QuestionWindow*>(source)->GetUi();
    if (ui.lastNameEdit->text() != "") {
        sourceUi.studentPrenume->setText(ui.lastNameEdit->text());
    }
    if (ui.firstNameEdit->text() != "") {
        sourceUi.studentNume->setText(ui.firstNameEdit->text());
    }
    source->show();
    close();
}