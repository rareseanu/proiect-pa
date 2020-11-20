#pragma once
#include <vector>
#include "Question.h"
#include "Answer.h"
#include "DatabaseHandler.h"

class QuestionnaireFramework
{
public:
	void loadQuestions();
	void openDatabase(const std::string& databaseName, const std::string& databaseHost, const std::string& databasePort,
		const  std::string& databaseUser, const std::string& databasePassword);
	void printQuestions() const;

private:
	std::vector<Question> m_questions;
	DatabaseHandler* dh;
};

