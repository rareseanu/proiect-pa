#pragma once
#include "QuestionnaireFramework.h"
#include "Logger.h"
#include "Timer.h"

class TerminalQuestionnaire
{
public:
	TerminalQuestionnaire(int numberOfQuestionsNeeded, int quizTime);
	void Start();
	void Stop();
	void PrintAllQuestions() const;
	void PrintQuestionsFromCategory(const std::string& category) const;
	void PrintSelectedQuestions() const;
	void PrintTimeLeft() const;
	void PrintResults() const;
private:
	QuestionnaireFramework quiz = QuestionnaireFramework(true);
	std::vector<Question>* m_selectedQuestions;
};

