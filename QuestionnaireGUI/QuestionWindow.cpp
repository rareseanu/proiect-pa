#include "QuestionWindow.h"
#include <QtWidgets/QMessageBox>

QuestionWindow::QuestionWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    startWindow.show();
    
    connect(ui.finishButton, &QPushButton::pressed, this, &QuestionWindow::OpenDialog);
    QObject::connect(qApp, &QGuiApplication::applicationStateChanged, this, [=](Qt::ApplicationState state) {
        on_focusLoss();
        });
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
    Ui::SendDialog sendDialogUi = sendDialog.GetUi();
    sendDialogUi.nameLabel->setText(ui.studentNume->text() + " " + ui.studentPrenume->text());
    sendDialog.show();
}

void QuestionWindow::on_focusLoss()
{
    //open a dialog to inform about the focus loss
}

Ui::QuestionWindow QuestionWindow::GetUi()
{
    return ui;
}
