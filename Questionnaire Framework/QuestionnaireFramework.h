#pragma once
#include "Question.h"
#include "Answer.h"
#include "DatabaseHandler.h"
#include <unordered_map>
#include <vector>

class QuestionnaireFramework
{
public:
	void loadQuestions();
	void openDatabase(const std::string& databaseName, const std::string& databaseHost, const std::string& databasePort,
		const  std::string& databaseUser, const std::string& databasePassword);
	void printQuestions() const;
	const std::vector<Question>& getQuestionsFromCategory(const std::string& category) const;
	void printQuestionsFromCategory(const std::string& category) const;

private:
	std::unordered_map<std::string, std::vector<Question>> m_questions;
	DatabaseHandler* dh;
};

