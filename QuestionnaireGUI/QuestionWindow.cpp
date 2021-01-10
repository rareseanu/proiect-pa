#include "QuestionWindow.h"
#include <QtWidgets/QMessageBox>

QuestionWindow::QuestionWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    startWindow.show();
    startWindow.setFocus();
    quiz.SetQuizTime(10);
    quiz.SetNumberOfQuestions(4);
    try {
        quiz.OpenDatabase("yufioaba", "ruby.db.elephantsql.com", "5432", "yufioaba", "ZGnmR5rJdvvkXXove7sqUQGNB5-lHNoO");
    }
    catch (std::string error) {
        std::cout << error;
        LOG_ERROR(error);
        exit(0);
    }
    srand(time(NULL));
    quiz.LoadQuestions("question", "answer");
    quiz.SelectQuestions(std::vector<std::string> {"SA", "Mate"});
    m_selectedQuestions = quiz.GetSelectedQuestions();
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
        fraudDialog.exec();
}

void QuestionWindow::StartQuiz()
{
    
}

Ui::QuestionWindow QuestionWindow::GetUi()
{
    return ui;
}
