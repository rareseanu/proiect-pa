#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QuestionForm.h"
#include "FinishDialog.h"
#include "StartWindow.h"
#include "SendDialog.h"
#include "FraudDialog.h"
#include <QuestionnaireFramework.h>

class QuestionWindow : public QMainWindow
{
    Q_OBJECT

public:
    QuestionWindow(QWidget* parent = nullptr);
    void OpenDialog();
    void on_btnClose_clicked();
    void on_focusLoss(int);
    void StartQuiz();
    Ui::QuestionWindow GetUi();
 
private:
    Ui::QuestionWindow ui;
    FinishDialog finishDialog;
    StartWindow startWindow=StartWindow(this);
    SendDialog sendDialog;
    QuestionnaireFramework quiz = QuestionnaireFramework(true, false, L"Qt600dQWindowIcon");
    std::vector<Question>* m_selectedQuestions;
    FraudDialog fraudDialog;
};
