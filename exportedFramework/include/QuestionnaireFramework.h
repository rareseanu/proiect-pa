#pragma once
#include "Question.h"
#include "Answer.h"
#include "DatabaseHandler.h"
#include <time.h>       
#include "User.h"
#include "Timer.h"
#include "Logger.h"
#include <unordered_map>
#include <vector>
#include <memory>
#include <optional>
#include "WindowsAPIUtils.h"

class QuestionnaireFramework
{
public:
	__declspec(dllexport) QuestionnaireFramework(int defaultGrade, bool anticheatingEnabled, bool isConsole, bool loggerEnabled = true);
	__declspec(dllexport) void LoadQuestions();
	__declspec(dllexport) void OpenDatabase(const std::string& databaseName, const std::string& databaseHost, const std::string& databasePort,
											const  std::string& databaseUser, const std::string& databasePassword);
	__declspec(dllexport) const std::vector<Question>& GetQuestionsFromCategory(const std::string& category) const;
	__declspec(dllexport) void SetNumberOfQuestions(int number);
	__declspec(dllexport) int GetNumberOfQuestions()const;
	__declspec(dllexport) void SetQuizTime(int seconds);
	__declspec(dllexport) int GetQuizTime();
	__declspec(dllexport) int GetMaximumGrade();
	__declspec(dllexport) int GetDefaultGrade();
	__declspec(dllexport) void SetMaximumGrade(int maxGrade);
	__declspec(dllexport) void SetCanAnswer(bool canAnswer);
	__declspec(dllexport) bool CanAnswer();
	__declspec(dllexport) const std::unordered_map<std::string, std::vector<Question>>& GetAllQuestions() const;
	__declspec(dllexport) void SelectQuestions(const std::vector<std::string>& categories);
	__declspec(dllexport) const std::shared_ptr<std::vector<Question>> GetSelectedQuestions()const;
	__declspec(dllexport) std::shared_ptr <std::vector<Question>> GetSelectedQuestions();
	__declspec(dllexport) int GetMaximumMark()const;
	__declspec(dllexport) void SetUser(const std::string& userTable, const std::string& nameColumn,
									   const std::optional<std::string>& startTimeColumn = std::nullopt);
	__declspec(dllexport) User& GetUser();
	__declspec(dllexport) void CalculateFinalGrade();
	__declspec(dllexport) void SetCheatingDetected();
	__declspec(dllexport) bool CheatingDetected();
	__declspec(dllexport) float GetFinalGrade()const;
	__declspec(dllexport) void StartTimer();
	__declspec(dllexport) void SetQuestionsTable(const std::string& qTable, const std::string& qIdColumn, const std::string& qTextColumn,
												const std::string& qPointsColumn, const std::string& qCategoryColumn, 
												const std::string& qQuestionTypeColumn);
	__declspec(dllexport) void SetAnswersTable(const std::string& aTable, const std::string& aIdColumn, const std::string& aTextColumn, 
												const std::string& aPercentageColumn, const std::string& aQuestionId);
	__declspec(dllexport) void StopTimer();
	__declspec(dllexport) const Timer& GetTimer()const;
	__declspec(dllexport) void SetTimerFunction(const std::function<void()>& funcToRun);
	__declspec(dllexport) void SendResult(const std::optional <std::string>& userTable = std::nullopt, 
										  const std::optional <std::string>& gradeColumn = std::nullopt,
										  const std::optional <std::string>& endTimeColumn = std::nullopt);
	__declspec(dllexport) const HHOOK& GetWindowsHook();
	__declspec(dllexport) void SetupAnticheating(const std::wstring& oldTitle);
	__declspec(dllexport) void SetUserAnswerTable(const std::string& uaTable, const std::string& uaUserIdColumn, const std::string& uaGivenAnswerColumn, const std::string& uaQuestionIdColumn);
private:
	int m_numberOfQuestionsNeeded = 0;
	int m_totalNumberOfQuestions = 0;
	int m_maximumMark = 0;
	int m_maximumGrade = 10;
	int m_defaultGrade = 1;
	int m_quizTime = 0;
	float m_finalGrade = 0;
	bool m_canAnswer = false;
	Timer m_timer;
	User m_user;
	std::string m_qIdColumn;
	std::string m_qTable;
	std::string m_qTextColumn;
	std::string m_qPointsColumn;
	std::string m_qCategoryColumn;
	std::string m_qQuestionTypeColumn;
	std::string m_aTable;
	std::string m_aIdColumn;
	std::string m_aTextColumn;
	std::string m_aPercentageColumn;
	std::string m_aQuestionIdColumn;
	std::string m_uaTable;
	std::string m_uaUserIdColumn;
	std::string m_uaGivenAnswerColumn;
	std::string m_uaQuestionIdColumn;
	time_t m_currentTime = NULL;
	std::unordered_map<std::string, std::vector<Question>> m_questions;
	std::unique_ptr<DatabaseHandler> dh = NULL;
	std::shared_ptr<std::vector<Question>> m_selectedQuestions = std::make_shared< std::vector<Question>>();
	HHOOK m_hook = NULL;
	bool cheatDetected = false;
	bool m_isConsole = false;
	
};