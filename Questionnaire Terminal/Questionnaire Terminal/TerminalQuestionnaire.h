#pragma once
#include "QuestionnaireFramework.h"

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
	QuestionnaireFramework m_quiz = QuestionnaireFramework(true, true, true);
	std::shared_ptr<std::vector<Question>> m_selectedQuestions = std::make_shared<std::vector<Question>>();
};

