#include "QuestionWindow.h"
#include <QtWidgets/QMessageBox>

QuestionWindow::QuestionWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    startWindow.show();
    startWindow.setFocus();
    m_quiz.SetQuizTime(10);
    m_quiz.SetNumberOfQuestions(4);
    try {
        m_quiz.OpenDatabase("yufioaba", "ruby.db.elephantsql.com", "5432", "yufioaba", "ZGnmR5rJdvvkXXove7sqUQGNB5-lHNoO");
    }
    catch (std::string error) {
        LOG_ERROR(error);
        exit(0);
    }
    srand(time(NULL));
    m_quiz.LoadQuestions("question", "answer");
    m_quiz.SelectQuestions(std::vector<std::string> {"SA", "Mate"});
    m_selectedQuestions = m_quiz.GetSelectedQuestions();
    connect(this, &QuestionWindow::WindowClosed, this, &QuestionWindow::StopQuiz);
}

void QuestionWindow::closeEvent(QCloseEvent* event)
{
    emit WindowClosed();
    event->accept();
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

void QuestionWindow::StartQuiz()
{
    m_quiz.GetUser().SetFirstName(ui.studentNume->text().toStdString());
    m_quiz.GetUser().SetLastName(ui.studentPrenume->text().toStdString());
    bool stillHasQuestions = true;
    int currentQuestion = 0;
    m_quiz.SetTimerFunction(std::bind(&QuestionWindow::StopQuiz, this));
    m_quiz.StartTimer();
    ShowQuestion(0);
}

void QuestionWindow::StopQuiz()
{
   m_quiz.StopTimer();
}

void QuestionWindow::CreateAnswerFrame(Question question)
{
    ui.answerChoiceBox->setTitle(QString::fromStdString(Question::ConvertQuestionTypeToString(question.GetQuestionType())));
    if (question.GetQuestionType() == Question::QuestionType::Singlechoice) {
        char answerSymbol = 'a';
        int i = 0;
        for (Answer answer : question.GetAnswers()) {
            QRadioButton* answerRadioButton = new QRadioButton(ui.answerChoiceBox);
            std::string answerObjectName(1, (char)answerSymbol++);
            answerRadioButton->setObjectName(QString::fromStdString(answerObjectName));
            answerRadioButton->setText(QString::fromStdString(answer.GetAnswer()));
            ((QGridLayout*)ui.answerChoiceBox->layout())->addWidget(answerRadioButton,i/(int)sqrt(question.GetAnswers().size()),i%(int)sqrt(question.GetAnswers().size()),Qt::AlignCenter);
            answerButtons.push_back(answerRadioButton);
            ++i;
        }
    }
    else if (question.GetQuestionType() == Question::QuestionType::Multichoice) {
        char answerSymbol = 'a';
        int i = 0;
        for (Answer answer : question.GetAnswers()) {
            QCheckBox* answerCheckBox = new QCheckBox(ui.answerChoiceBox);
            std::string answerObjectName(1, (char)answerSymbol++);
            answerCheckBox->setObjectName(QString::fromStdString(answerObjectName));
            answerCheckBox->setText(QString::fromStdString(answer.GetAnswer()));
            ((QGridLayout*)ui.answerChoiceBox->layout())->addWidget(answerCheckBox, i / (int)sqrt(question.GetAnswers().size()), i % (int)sqrt(question.GetAnswers().size()), Qt::AlignCenter);
            answerButtons.push_back(answerCheckBox);
            ++i;
        }
    }
    else if (question.GetQuestionType() == Question::QuestionType::Text) {
        textAnswer = new QTextEdit(ui.answerChoiceBox);
        textAnswer->setObjectName(QString::fromStdString("textAnswer"));
        ((QGridLayout*)ui.answerChoiceBox->layout())->addWidget(textAnswer, 0, 0);
    }
}

void QuestionWindow::ShowQuestion(int questionNumber)
{
	/*if (m_quiz.CheatingDetected()) {
		fraudDialog.exec();
	}*/
    if (m_quiz.CanAnswer()) {
        std::string textCurrentQuestion = "Question: " + std::to_string(questionNumber+1) + "/" + std::to_string(m_selectedQuestions->size());
        ui.questionNumberLabel->setText(QString::fromStdString(textCurrentQuestion));
        QString questionText = QString::fromStdString(m_selectedQuestions->at(questionNumber).GetText());
        ui.questionLabel->setText(questionText);
        CreateAnswerFrame(m_selectedQuestions->at(questionNumber));
    }
    else {
        m_quiz.StopTimer();
    }
}

Ui::QuestionWindow QuestionWindow::GetUi()
{
    return ui;
}
