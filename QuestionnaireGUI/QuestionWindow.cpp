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
        on_btnClose_clicked();
    }
}

void QuestionWindow::on_btnClose_clicked()
{
    this->hide();
    sendDialog.show();
}

Ui::QuestionWindow QuestionWindow::GetUi()
{
    return ui;
}
