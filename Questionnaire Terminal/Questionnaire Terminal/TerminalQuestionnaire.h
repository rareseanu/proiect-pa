#pragma once
#include "QuestionnaireFramework.h"
#include <optional>

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
	QuestionnaireFramework m_quiz = QuestionnaireFramework(10, true, true, true);
	std::shared_ptr<std::vector<Question>> m_selectedQuestions;
};

