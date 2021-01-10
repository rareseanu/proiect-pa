#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QuestionForm.h"
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
    void OpenDialog();
    void on_btnClose_clicked();
    void StartQuiz();
    void StopQuiz();
    void CreateAnswerFrame(Question question);
    void ShowQuestion(int questionNumber);
    Ui::QuestionWindow GetUi();

signals:
    void WindowClosed();
 
private:
    Ui::QuestionWindow ui;
    FinishDialog finishDialog;
    StartWindow startWindow=StartWindow(this);
    SendDialog sendDialog;
    std::vector<QAbstractButton*> answerButtons;
    QTextEdit* textAnswer;
    QuestionnaireFramework m_quiz = QuestionnaireFramework(true, false, L"Qt600dQWindowIcon");
    std::vector<Question>* m_selectedQuestions;
    FraudDialog fraudDialog;
};
