#pragma once
#include "Question.h"
#include "Answer.h"
#include "DatabaseHandler.h"
#include <time.h>       
#include "Timer.h"
#include <unordered_map>
#include <vector>

class QuestionnaireFramework
{
public:
	QuestionnaireFramework(int numberOfQuestionsNeeded);
	void loadQuestions(const std::string& questionTable, const std::string& answerTable);
	void openDatabase(const std::string& databaseName, const std::string& databaseHost, const std::string& databasePort,
		const  std::string& databaseUser, const std::string& databasePassword);
	void printAllQuestions() const;
	const std::vector<Question>& getQuestionsFromCategory(const std::string& category) const;
	void printQuestionsFromCategory(const std::string& category) const;
	void setNumberOfQuestions(int number);
	int getNumberOfQuestions();
	void selectQuestions(const std::vector<std::string>& categories);
	void printQuestions(const std::vector<Question>& vectorQuestions);
	const std::vector<Question>& getSelectedQuestions();
	void start();
	void stop();
	int getMaximumMark();
private:
	int m_numberOfQuestionsNeeded;
	int m_totalNumberOfQuestions;
	int m_maximumMark;
	bool m_canAnswer;
	std::unordered_map<std::string, std::vector<Question>> m_questions;
	DatabaseHandler* dh;
	std::vector<Question> m_selectedQuestions;
};

