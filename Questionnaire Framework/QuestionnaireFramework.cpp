#include "QuestionnaireFramework.h"
#include <vector>
#include <string>
#include <thread>
#include "Logger.h"

QuestionnaireFramework::QuestionnaireFramework(int defaultGrade, bool anticheatingEnabled, bool isConsole, bool loggerEnabled)
	: m_isConsole(isConsole), m_defaultGrade(defaultGrade)
{
	if (loggerEnabled) {
		Logger::ActivateLogger();
	}
}

void QuestionnaireFramework::LoadQuestions() {
	std::string command = "select "+m_qIdColumn+","+ m_qTextColumn + "," + m_qPointsColumn 
		+ "," + m_qCategoryColumn + "," + m_qQuestionTypeColumn + " from " + m_qTable +";";
	for (auto questionRow : dh->GetTableFromCommand(command)) {
		int id = std::stoi(questionRow[0]);
		std::string text = questionRow[1];
		int points = std::stoi(questionRow[2]);
		std::string category = questionRow[3];
		Question::QuestionType questionType;
		try {
			questionType = Question::ConvertStringToQuestionType(questionRow[4]);
		}
		catch(std::string error){
			LOG_ERROR(error);
			questionType = Question::QuestionType::Multichoice;
		}
		command = "select " + m_aIdColumn + "," + m_aTextColumn + "," + m_aPercentageColumn 
			+ " from " + m_aTable + " where " + m_aQuestionId +" = " + std::to_string(id) + ";";
		std::vector<std::vector<std::string>> answerTable = dh->GetTableFromCommand(command);
		std::vector<Answer> answers;

		for (auto answerRow : answerTable) {
			int id = std::stoi(answerRow[0]);
			std::string text = answerRow[1];
			float percentage = std::stof(answerRow[2]);
			if (std::find_if(answers.begin(), answers.end(), [&text](const Answer& answer) {  
					return answer.GetAnswer() == text; }) == answers.end()) {
				answers.push_back(Answer(id, text, percentage, false));
			}
			else {
				LOG_WARN("Answer aleady existent: " + text);
			}
		}
		if (answers.empty()) {
			LOG_WARN("Question has no answers: " + text);
		}
		else {
			m_questions[category].push_back(Question(id, text, points, category, answers, false,questionType));
		}
		++m_totalNumberOfQuestions;
	}
	if (m_totalNumberOfQuestions < m_numberOfQuestionsNeeded) {
		LOG_WARN("Not enough questions in the question bank.");
		m_numberOfQuestionsNeeded = m_totalNumberOfQuestions;
	}
}

void QuestionnaireFramework::OpenDatabase(const std::string& databaseName, const std::string& databaseHost, const std::string& databasePort,
	const  std::string& databaseUser, const std::string& databasePassword)
{
	dh.reset(new DatabaseHandler(databaseName, databaseHost, databasePort, databaseUser, databasePassword));
	if (!dh->IsConnected()) {
		throw std::string("Connection to the database failed.");
	}
}

const std::vector<Question>& QuestionnaireFramework::GetQuestionsFromCategory(const std::string& category) const
{
	auto it = m_questions.find(category);
	if (it != m_questions.end()) {
		return  m_questions.find(category)->second;
	}
	else {
		throw std::string("There are no questions in the given category (" + category + ").");
	}
}

void QuestionnaireFramework::SetNumberOfQuestions(int number)
{
	m_numberOfQuestionsNeeded = number;
}

int QuestionnaireFramework::GetNumberOfQuestions()const
{
	return m_numberOfQuestionsNeeded;
}

void QuestionnaireFramework::SetQuizTime(int seconds)
{
	m_quizTime = seconds;
}

int QuestionnaireFramework::GetQuizTime()
{
	return m_quizTime;
}

int QuestionnaireFramework::GetMaximumGrade()
{
	return m_maximumGrade;
}

int QuestionnaireFramework::GetDefaultGrade()
{
	return m_defaultGrade;
}

void QuestionnaireFramework::SetMaximumGrade(int maxGrade)
{
	m_maximumGrade = maxGrade;
}

void QuestionnaireFramework::SetCanAnswer(bool canAnswer)
{
	m_canAnswer = canAnswer;
}

bool QuestionnaireFramework::CanAnswer()
{
	return m_canAnswer;
}

const std::unordered_map<std::string, std::vector<Question>>& QuestionnaireFramework::GetAllQuestions() const
{
	return m_questions;
}

void QuestionnaireFramework::SelectQuestions(const std::vector<std::string>& categories)
{
	std::vector<Question> unchosenQuestions; //Vector to store remaining unchosen questions from each category.
	for (auto& category : categories) {
		size_t remainingNumberOfQuestions = m_numberOfQuestionsNeeded / categories.size();
		std::vector<Question> tempQuestions;
		try {
			tempQuestions = GetQuestionsFromCategory(category);
		}
		catch (std::string error) {
			std::cout << error;
			LOG_ERROR(error);
			exit(0);
		}
		// Add random question if the category has more questions than the necessary ammount.
		if (tempQuestions.size() > remainingNumberOfQuestions) {
			while (remainingNumberOfQuestions != 0) {
				int tempRand = rand() % tempQuestions.size();
				m_maximumMark += tempQuestions.at(tempRand).GetPoints();
				m_selectedQuestions->push_back(tempQuestions.at(tempRand));
				tempQuestions.erase(tempQuestions.begin() + tempRand);
				--remainingNumberOfQuestions;
			}
			unchosenQuestions.insert(unchosenQuestions.end(), tempQuestions.begin(), tempQuestions.end());
		}
		else { // Add the entire category when it has less questions than the necessary ammount.
			for (auto question : tempQuestions) {
				m_maximumMark += question.GetPoints();
				m_selectedQuestions->push_back(question);
			}
		}
	}
	// Add randomly chosen questions from the unchosen ones if needed.
	while (m_selectedQuestions->size() < m_numberOfQuestionsNeeded) {
		int tempRand = rand() % unchosenQuestions.size();
		m_maximumMark += unchosenQuestions.at(tempRand).GetPoints();
		m_selectedQuestions->push_back(unchosenQuestions.at(tempRand));
		unchosenQuestions.erase(unchosenQuestions.begin() + tempRand);
	}
}

const std::shared_ptr<std::vector<Question>> QuestionnaireFramework::GetSelectedQuestions()const
{
	return m_selectedQuestions;
}

std::shared_ptr<std::vector<Question>> QuestionnaireFramework::GetSelectedQuestions()
{
	return m_selectedQuestions;
}

int QuestionnaireFramework::GetMaximumMark()const
{
	return m_maximumMark;
}

void QuestionnaireFramework::SetUser(const std::string& userTable, const std::string& nameColumn
	, const std::optional<std::string>& startTimeColumn)
{
	if (m_isConsole) {
		std::cin >> m_user;
	}
	m_currentTime = time(NULL);
	tm convertedTime;
	localtime_s(&convertedTime, &m_currentTime);
	std::string command;
	if (startTimeColumn.has_value()) {
		command = "insert into " + userTable + "(" + nameColumn + "," + startTimeColumn.value() + ")"
			+ " values('" + m_user.GetName() + "','" + std::to_string(convertedTime.tm_hour)
			+ ":" + std::to_string(convertedTime.tm_min) + ":" + std::to_string(convertedTime.tm_sec) + "')";
	}
	else {
		command = "insert into " + userTable + "(" + nameColumn + ")" + " values('" + m_user.GetName() + "')";
	}
	dh->RunCommand(command);
	int id = stoi(dh->GetTableFromCommand("select max(s_id) from student").at(0).at(0));
	m_user.SetId(id);
}

User& QuestionnaireFramework::GetUser()
{
	return m_user;
}

void QuestionnaireFramework::CalculateFinalGrade()
{
	float percentage;
	float mark = 0;
	for (const Question& question : *m_selectedQuestions) {
		mark = mark + question.GetAquiredMark();
	}
	percentage = mark / m_maximumMark;
	m_user.SetGrade((m_maximumGrade - m_defaultGrade) * percentage + m_defaultGrade);
}

void QuestionnaireFramework::SetCheatingDetected() {
	cheatDetected = true;
}

bool QuestionnaireFramework::CheatingDetected()
{
	return cheatDetected;
}

float QuestionnaireFramework::GetFinalGrade() const
{
	return m_user.GetGrade();
}

void QuestionnaireFramework::StartTimer()
{
	std::thread timerThread(&Timer::Start, std::ref(m_timer));
	timerThread.detach();
	m_canAnswer = true;
}

void QuestionnaireFramework::SetQuestionsTable(const std::string& qTable, const std::string& qIdColumn, const std::string& qTextColumn,
	const std::string& qPointsColumn, const std::string& qCategoryColumn, const std::string& qQuestionTypeColumn)
{
	m_qTable = qTable;
	m_qIdColumn = qIdColumn;
	m_qTextColumn = qTextColumn;
	m_qPointsColumn = qPointsColumn;
	m_qCategoryColumn = qCategoryColumn;
	m_qQuestionTypeColumn = qQuestionTypeColumn;
}

void QuestionnaireFramework::SetAnswersTable(const std::string& aTable, const std::string& aIdColumn, 
	const std::string& aTextColumn, const std::string& aPercentageColumn, const std::string& aQuestionId)
{
	m_aTable = aTable;
	m_aIdColumn = aIdColumn;
	m_aTextColumn = aTextColumn;
	m_aPercentageColumn = aPercentageColumn;
	m_aQuestionId = aQuestionId;
}

void QuestionnaireFramework::StopTimer()
{
	m_timer.Stop();
}

const Timer& QuestionnaireFramework::GetTimer() const
{
	return m_timer;
}

void QuestionnaireFramework::SetTimerFunction(const std::function<void()>& funcToRun)
{
	m_timer.SetTimeout(funcToRun, m_quizTime);
}

void QuestionnaireFramework::SendResult(const std::string& userAnswerTable, const std::optional<std::string> &userTable,
	const std::optional <std::string>& gradeColumn, const std::optional <std::string>& endTimeColumn)
{
	m_currentTime = time(NULL);
	tm convertedTime;
	localtime_s(&convertedTime, &m_currentTime);
	std::string command;
	if(userTable.has_value()) {
		if (gradeColumn.has_value() && endTimeColumn.has_value()) {
			command = "update " + userTable.value() + " set " + gradeColumn.value() + "=" + std::to_string(m_user.GetGrade()) + ","
				+ endTimeColumn.value() + "='" + std::to_string(convertedTime.tm_hour) + ":" + std::to_string(convertedTime.tm_min) + ":"
				+ std::to_string(convertedTime.tm_sec) + "' where s_id=" + std::to_string(m_user.GetId()) + ";";
		}
		else if (gradeColumn.has_value()) {
			command = "update " + userTable.value() + " set " + gradeColumn.value()
				+ "=" + std::to_string(m_user.GetGrade()) + " where s_id=" + std::to_string(m_user.GetId()) + ";";
		}
		else if (endTimeColumn.has_value()) {
			command = "update " + userTable.value() + " set "
				+ endTimeColumn.value() + "='" + std::to_string(convertedTime.tm_hour) + ":" + std::to_string(convertedTime.tm_min) + ":"
				+ std::to_string(convertedTime.tm_sec) + "' where s_id=" + std::to_string(m_user.GetId()) + ";";
		}
	}

	for (Question question : *m_selectedQuestions) {
		if (question.GetQuestionType() == Question::QuestionType::Text) {
			command =command+ "insert into " + userAnswerTable + " values(" + std::to_string(m_user.GetId()) + ",'"
				+ question.GetGivenTextAnswer() + "'," + std::to_string(question.GetID()) + ");";
		}
		else {
			bool anythingAnswered = false;
			for (Answer answer : question.GetAnswers()) {
				if (answer.GetSelected()) {
					command = command + "insert into " + userAnswerTable + " values(" + std::to_string(m_user.GetId()) + ",'" 
						+ answer.GetAnswer() + "'," + std::to_string(question.GetID()) + ");";
					anythingAnswered = true;
				}
			}
			if (anythingAnswered == false) {
				command = command + "insert into " + userAnswerTable + " values(" + std::to_string(m_user.GetId()) 
					+ ",'" + "" + "'," + std::to_string(question.GetID()) + ");";
			}
		}
	}
	dh->RunCommand(command);
}

const HHOOK& QuestionnaireFramework::GetWindowsHook()
{
	return m_hook;
}

void QuestionnaireFramework::SetupAnticheating(const std::wstring &oldTitle)
{
	std::wstring windowTitle = GetUniqueWindowTitle();

	if (m_isConsole) {
		SetConsoleTitle((LPCWSTR)windowTitle.c_str());
		Sleep(1000);
		SetupConsoleAnticheat(this);
	}
	else {
		m_hook = SetupGUIAnticheat((LPCWSTR)oldTitle.c_str(), L"WindowsHooking.dll", this);
	}
}
