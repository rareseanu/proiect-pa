#include "QuestionWindow.h"
#include <QtWidgets/QMessageBox>

QuestionWindow::QuestionWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    startWindow.show();
    startWindow.setFocus();
    numberOfFocusLosses = 0;
    connect(ui.finishButton, &QPushButton::pressed, this, &QuestionWindow::OpenDialog);
    QObject::connect(qApp, &QGuiApplication::applicationStateChanged, this, [=](Qt::ApplicationState state) {
           on_focusLoss(numberOfFocusLosses);
           numberOfFocusLosses++;
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

void QuestionWindow::on_focusLoss(int numberOfFocusLosses)
{
    //open a dialog to inform about the focus loss
    if (numberOfFocusLosses)
    {
        close();
        Ui::SendDialog sendDialogUi = sendDialog.GetUi();
        sendDialogUi.nameLabel->setText(ui.studentNume->text() + " " + ui.studentPrenume->text());
        sendDialog.exec();
    }
}

Ui::QuestionWindow QuestionWindow::GetUi()
{
    return ui;
}
