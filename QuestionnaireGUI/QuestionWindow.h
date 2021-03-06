#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QuestionForm.h"
#include "HelpDialog.h"
#include "FinishDialog.h"
#include "StartWindow.h"
#include "SendDialog.h"
#include "FraudDialog.h"
#include <QuestionnaireFramework.h>
#include <QtWidgets>

class QuestionWindow : public QMainWindow
{
    Q_OBJECT

public:
    QuestionWindow(QWidget* parent = nullptr);
    void closeEvent(QCloseEvent* event);
    void StartQuiz();
    void StopQuiz();
    void CreateAnswerFrame(Question question);
    void HelpButtonClicked();
    void NextButtonClicked();
    void BackButtonClicked();
    void FinishButtonClicked();
    void SaveAnswer(int questionNumber);
    void LoadAnswer(int questionNumber);
    void ForceStop();
    void ClearButtonClicked();
    void ShowTimeLeft();
    void ResetAnswerFrame();
    void ShowQuestion(int questionNumber);
    Ui::QuestionWindow GetUi();

signals:
    void WindowClosed();
 
private:
    Ui::QuestionWindow ui;
    HelpDialog helpDialog;
    FinishDialog finishDialog;
    StartWindow startWindow=StartWindow(this);
    SendDialog sendDialog;
    std::vector<QAbstractButton*> answerButtons;
    QTextEdit* textAnswer = NULL;
    int currentQuestion = 0;
    QTimer timer;
    QuestionnaireFramework m_quiz = QuestionnaireFramework(1,true, false);
    std::shared_ptr<std::vector<Question>> m_selectedQuestions;
    FraudDialog fraudDialog;
    std::string startTime;
    std::string stopTime;
};
