#pragma once
#include "Question.h"
#include "Answer.h"
#include "DatabaseHandler.h"
#include <time.h>       
#include "User.h"
#include "Timer.h"
#include <unordered_map>
#include <vector>

class QuestionnaireFramework
{
public:
	QuestionnaireFramework(int numberOfQuestionsNeeded,int quizTime);
	void LoadQuestions(const std::string& questionTable, const std::string& answerTable);
	void OpenDatabase(const std::string& databaseName, const std::string& databaseHost, const std::string& databasePort,
		const  std::string& databaseUser, const std::string& databasePassword);
	void PrintAllQuestions() const;
	const std::vector<Question>& GetQuestionsFromCategory(const std::string& category) const;
	void PrintQuestionsFromCategory(const std::string& category) const;
	void SetNumberOfQuestions(int number);
	int GetNumberOfQuestions()const;
	void SelectQuestions(const std::vector<std::string>& categories);
	void PrintSelectedQuestions() const;
	void PrintResults() const;
	void PrintQuestions(const std::vector<Question>& vectorQuestions)const;
	const std::vector<Question>& GetSelectedQuestions()const;
	void Start();
	void Stop();
	int GetMaximumMark()const;
	void SetUser(const std::string& lastName, const std::string& firstName);
	void CalculateFinalGrade();
	float GetFinalGrade()const;
private:
	int m_numberOfQuestionsNeeded;
	int m_totalNumberOfQuestions;
	int m_maximumMark;
	int m_quizTime;
	float m_finalGrade;
	bool m_canAnswer;
	User m_user;
	std::unordered_map<std::string, std::vector<Question>> m_questions;
	DatabaseHandler* dh;
	std::vector<Question> m_selectedQuestions;
};

