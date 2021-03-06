#include "QuestionWindow.h"
#include <QtWidgets/QMessageBox>
#include <chrono>
#include <ctime>
#include <time.h>

QuestionWindow::QuestionWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    startWindow.show();
    startWindow.setFocus();
    m_quiz.SetQuizTime(300);
    m_quiz.SetNumberOfQuestions(10);
    m_quiz.SetMaximumGrade(10);
    try {
        m_quiz.OpenDatabase("yufioaba", "ruby.db.elephantsql.com", "5432", "yufioaba", "ZGnmR5rJdvvkXXove7sqUQGNB5-lHNoO");
    }
    catch (std::string error) {
        LOG_ERROR(error);
        exit(0);
    }
    srand(time(NULL));
    m_quiz.SetQuestionsTable("question", "q_id", "text", "points", "category", "type");
    m_quiz.SetAnswersTable("answer", "a_id", "text", "percentage", "q_id");
    m_quiz.SetUserAnswerTable("student_raspuns", "s_id", "raspuns", "q_id");
    m_quiz.LoadQuestions();
    m_quiz.SelectQuestions(std::vector<std::string> {"Baze de date"});
    m_selectedQuestions = m_quiz.GetSelectedQuestions();
    ui.backButton->setEnabled(false);
    connect(this, &QuestionWindow::WindowClosed, this, &QuestionWindow::FinishButtonClicked);
    connect(ui.helpButton, &QPushButton::clicked, this, &QuestionWindow::HelpButtonClicked);
    connect(ui.nextButton, &QPushButton::clicked, this, &QuestionWindow::NextButtonClicked);
    connect(ui.backButton, &QPushButton::clicked, this, &QuestionWindow::BackButtonClicked);
    connect(ui.clearButton, &QPushButton::clicked, this, &QuestionWindow::ClearButtonClicked);
    connect(ui.finishButton, &QPushButton::clicked, this, &QuestionWindow::FinishButtonClicked);
}

void QuestionWindow::closeEvent(QCloseEvent* event)
{
    emit WindowClosed();
    if (finishDialog.result() == QDialog::Accepted) {
       event->accept();
    }
    event->ignore();
}

void QuestionWindow::StartQuiz()
{
    hide();
    m_quiz.SetupAnticheating("Questionnaire");
    show();
    m_quiz.GetUser().SetFirstName(ui.studentNume->text().toStdString());
    m_quiz.GetUser().SetLastName(ui.studentPrenume->text().toStdString());
    m_quiz.SetUser("student", "nume", "time_start");
    m_quiz.SetTimerFunction(std::bind(&QuestionWindow::ForceStop, this));
    m_quiz.StartTimer();   
    connect(&timer, &QTimer::timeout, this, &QuestionWindow::ShowTimeLeft);
    timer.start(0);
    std::time_t now = std::time(NULL);
    std::tm ptm = *std::localtime(&now);
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(2) << std::to_string(ptm.tm_hour) << ":" 
            << std::setw(2) << std::to_string(ptm.tm_min) << ":" 
            << std::setw(2) << std::to_string(ptm.tm_sec) << std::setfill(' ');
    startTime = stream.str();
    ShowQuestion(currentQuestion);
}

void QuestionWindow::StopQuiz()
{
    timer.stop();
    m_quiz.SetCanAnswer(false);
    m_quiz.CalculateFinalGrade();
    if (m_quiz.CheatingDetected()) {
        m_quiz.GetUser().SetGrade(m_quiz.GetDefaultGrade());
    }
    m_quiz.SendResult("student", "nota", "time_end");
    m_quiz.StopTimer();
    if (m_quiz.GetCallWndHook() != NULL) {
        UnhookWindowsHookEx(m_quiz.GetCallWndHook());
    }
    if(m_quiz.GetMouseHook() != NULL) {
       UnhookWindowsHookEx(m_quiz.GetMouseHook());
    }
    this->hide();
    this->destroy();
    Ui::SendDialog sendDialogUi = sendDialog.GetUi();
    sendDialogUi.nameLabel->setText(ui.studentNume->text() + " " + ui.studentPrenume->text());
    sendDialogUi.actualMarkLabel->setText(QString::fromStdString(std::to_string(m_quiz.GetFinalGrade()).substr(0,6) + "/" + std::to_string(m_quiz.GetMaximumGrade())));
    sendDialogUi.time1Label->setText(QString::fromStdString(startTime));

    std::time_t now = std::time(NULL);
    std::tm ptm = *std::localtime(&now);
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(2) << std::to_string(ptm.tm_hour) << ":" 
            << std::setw(2) << std::to_string(ptm.tm_min) << ":" 
            << std::setw(2) << std::to_string(ptm.tm_sec) << std::setfill(' ');
    stopTime = stream.str();
    sendDialogUi.time2Label->setText(QString::fromStdString(stopTime));

    QFont font = sendDialogUi.time2Label->font();
    font.setPointSize(12);
    sendDialogUi.time1Label->setFont(font);
    sendDialogUi.time1Label->setAlignment(Qt::AlignCenter);
    sendDialogUi.time2Label->setFont(font);
    sendDialogUi.time2Label->setAlignment(Qt::AlignCenter);

    sendDialog.show();
    if (m_quiz.CheatingDetected()) {
        fraudDialog.show();
    }
}

void QuestionWindow::CreateAnswerFrame(Question question)
{
    ui.answerChoiceBox->setTitle(QString::fromStdString(Question::ConvertQuestionTypeToString(question.GetQuestionType())));
    if (question.GetQuestionType() == Question::QuestionType::Singlechoice) {
        char answerSymbol = 'a';
        int i = 0;
        for (Answer answer : question.GetAnswers()) {
            QPushButton* answerCheckBox = new QPushButton(ui.answerChoiceBox);
            answerCheckBox->setMaximumSize(9999, 9999);
            answerCheckBox->setMinimumSize(0, 0);
            QSizePolicy sizePolicy;
            sizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
            sizePolicy.setVerticalPolicy(QSizePolicy::Minimum);
            answerCheckBox->setSizePolicy(sizePolicy);
            answerCheckBox->setCheckable(true);
            answerCheckBox->setAutoExclusive(true);
            std::string answerObjectName(1, (char)answerSymbol++);
            answerCheckBox->setObjectName(QString::fromStdString(answerObjectName));
            answerCheckBox->setText(QString::fromStdString(answer.GetAnswer()));
            ui.answerChoiceLayout->addWidget(answerCheckBox, i / (int)sqrt(question.GetAnswers().size()), i % (int)sqrt(question.GetAnswers().size()));
            answerButtons.push_back(answerCheckBox);
            ++i;
        }
    }
    else if (question.GetQuestionType() == Question::QuestionType::Multichoice) {
        char answerSymbol = 'a';
        int i = 0;
        for (Answer answer : question.GetAnswers()) {
            QPushButton* answerCheckBox = new QPushButton(ui.answerChoiceBox);
            answerCheckBox->setMaximumSize(9999, 9999);
            answerCheckBox->setMinimumSize(0, 0);
            QSizePolicy sizePolicy;
            sizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
            sizePolicy.setVerticalPolicy(QSizePolicy::Minimum);
            answerCheckBox->setSizePolicy(sizePolicy);
            answerCheckBox->setCheckable(true);
            std::string answerObjectName(1, (char)answerSymbol++);
            answerCheckBox->setObjectName(QString::fromStdString(answerObjectName));
            answerCheckBox->setText(QString::fromStdString(answer.GetAnswer()));
            ui.answerChoiceLayout->addWidget(answerCheckBox, i / (int)sqrt(question.GetAnswers().size()), i % (int)sqrt(question.GetAnswers().size()));
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

void QuestionWindow::HelpButtonClicked()
{
    helpDialog.exec();
}

void QuestionWindow::NextButtonClicked()
{
    if (m_quiz.CanAnswer()) {
        ui.backButton->setEnabled(true);
        SaveAnswer(currentQuestion);
        ++currentQuestion;
        ResetAnswerFrame();
        ShowQuestion(currentQuestion);
        LoadAnswer(currentQuestion);
        if (currentQuestion == m_selectedQuestions->size() - 1) {
            ui.nextButton->clearFocus();
            ui.nextButton->setEnabled(false);
        }
    }
}

void QuestionWindow::BackButtonClicked()
{
    if (m_quiz.CanAnswer()) {
        ui.nextButton->setEnabled(true);
        SaveAnswer(currentQuestion);
        --currentQuestion;
        ResetAnswerFrame();
        ShowQuestion(currentQuestion);
        LoadAnswer(currentQuestion);
        if (currentQuestion == 0) {
            ui.backButton->clearFocus();
            ui.backButton->setEnabled(false);
        }
    }
}

void QuestionWindow::FinishButtonClicked()
{
    finishDialog.exec();
    if (finishDialog.result() == QDialog::Accepted) {
        SaveAnswer(currentQuestion);
        ResetAnswerFrame();
        StopQuiz();
    }
}

void QuestionWindow::SaveAnswer(int questionNumber)
{
    std::string answer="";
    for (QAbstractButton* button : answerButtons) {
        if (button->isChecked()) {
            answer = answer + button->objectName().toStdString();
        }
    }
    if (textAnswer) {
        answer = answer + textAnswer->toPlainText().toStdString();
    }
    m_selectedQuestions->at(questionNumber).GiveAnswer(answer);
}

void QuestionWindow::LoadAnswer(int questionNumber)
{
    int i = 0;
    if (answerButtons.size() != 0) {
        for (Answer answer : m_selectedQuestions->at(questionNumber).GetAnswers()) {
            if (answer.GetSelected()) {
                answerButtons.at(i)->setChecked(true);
            }
            ++i;
        }
    }
    else {
        textAnswer->setText(QString::fromStdString(m_selectedQuestions->at(questionNumber).GetGivenTextAnswer()));
    }
}

void QuestionWindow::ForceStop()
{
    SaveAnswer(currentQuestion);
    m_quiz.SetCanAnswer(false);
}

void QuestionWindow::ClearButtonClicked()
{
    if (answerButtons.size() != 0) {
        for (QAbstractButton* answer : answerButtons) {
            answer->setChecked(false);
        }
    }
    else {
        textAnswer->setText("");
    }
}

void QuestionWindow::ShowTimeLeft()
{
    int seconds = m_quiz.GetTimer().GetTimeLeft() % 60;
    int minutes = (m_quiz.GetTimer().GetTimeLeft() / 60) % 60;
    int hours = (m_quiz.GetTimer().GetTimeLeft() / 60 / 60) % 24;
    std::stringstream stringStream;
    stringStream << "Time left: " << std::setw(2) << std::setfill('0') << hours
        << ":" << std::setw(2) << minutes
        << ":" << std::setw(2) << seconds << '\n' << std::setfill(' ');
    ui.timeLabel->setText(QString::fromStdString(stringStream.str()));
    if (m_quiz.CheatingDetected()) {
        ForceStop();
    }
    if (!m_quiz.CanAnswer()) {
        timer.stop();
        StopQuiz();
    }
}

void QuestionWindow::ResetAnswerFrame()
{
    for (QAbstractButton* button : answerButtons) {
        button->parentWidget()->layout()->removeWidget(button);
        delete button;
    }
    if (textAnswer) {
       textAnswer->parentWidget()->layout()->removeWidget(textAnswer);
       delete textAnswer;
       textAnswer = NULL;
    }
    answerButtons.clear();
}

void QuestionWindow::ShowQuestion(int questionNumber)
{
    std::string textCurrentQuestion = "Question: " + std::to_string(questionNumber+1) + "/" + std::to_string(m_selectedQuestions->size());
    std::string categoryText = "Category: " + m_selectedQuestions->at(questionNumber).GetCategory();
    ui.questionNumberLabel->setText(QString::fromStdString(textCurrentQuestion));
    ui.categoryLabel->setText(QString::fromStdString(categoryText));
    QString questionText = QString::fromStdString(m_selectedQuestions->at(questionNumber).GetText());
    ui.questionLabel->setText(questionText);
    CreateAnswerFrame(m_selectedQuestions->at(questionNumber));
}

Ui::QuestionWindow QuestionWindow::GetUi()
{
    return ui;
}
