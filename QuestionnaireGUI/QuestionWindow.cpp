#include "QuestionWindow.h"
#include <QtWidgets/QMessageBox>

QuestionWindow::QuestionWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    startWindow.show();
    connect(ui.finishButton, &QPushButton::pressed, this, &QuestionWindow::OpenDialog);
}

void QuestionWindow::OpenDialog() {
    finishDialog.exec();
    if (finishDialog.result() == QDialog::Accepted) {
        close();
    }
}

Ui::QuestionWindow QuestionWindow::GetUi()
{
    return ui;
}
