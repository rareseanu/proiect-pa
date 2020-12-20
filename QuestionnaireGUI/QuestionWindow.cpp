#include "QuestionWindow.h"
#include <QtWidgets/QMessageBox>

QuestionWindow::QuestionWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    startWindow.show();
    connect(ui.finishButton, &QPushButton::pressed, this, &QuestionWindow::openDialog);
}

void QuestionWindow::openDialog() {

}