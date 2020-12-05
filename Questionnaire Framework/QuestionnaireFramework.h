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
	QuestionnaireFramework(bool loggerEnabled = true);
	void LoadQuestions(const std::string& questionTable, const std::string& answerTable);
	void OpenDatabase(const std::string& databaseName, const std::string& databaseHost, const std::string& databasePort,
		const  std::string& databaseUser, const std::string& databasePassword);
	const std::vector<Question>& GetQuestionsFromCategory(const std::string& category) const;
	void SetNumberOfQuestions(int number);
	int GetNumberOfQuestions()const;
	void SetQuizTime(int seconds);
	int GetQuizTime();
	void SetCanAnswer(bool canAnswer);
	bool CanAnswer();
	const std::unordered_map<std::string, std::vector<Question>>& GetAllQuestions() const;
	void SelectQuestions(const std::vector<std::string>& categories);
	const std::vector<Question>& GetSelectedQuestions()const;
	std::vector<Question>* GetSelectedQuestions();
	int GetMaximumMark()const;
	void SetUser(const std::string& lastName, const std::string& firstName);
	User& GetUser();
	void CalculateFinalGrade();
	float GetFinalGrade()const;
	void StartTimer();
	void StopTimer();
	const Timer& GetTimer()const;
	void SetTimerFunction(const std::function<void()>& funcToRun);
	void SendResult(const std::string & tableName, const std::string& nameColumn, const std::string& gradeColumn)const;
private:
	int m_numberOfQuestionsNeeded = 0;
	int m_totalNumberOfQuestions = 0;
	int m_maximumMark = 0;
	int m_quizTime = 0;
	float m_finalGrade = 0;
	bool m_canAnswer = false;
	Timer m_timer;
	User m_user;
	std::unordered_map<std::string, std::vector<Question>> m_questions;
	DatabaseHandler* dh = NULL;
	std::vector<Question> m_selectedQuestions;
};