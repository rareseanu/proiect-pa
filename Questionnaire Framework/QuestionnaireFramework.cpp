#include "QuestionnaireFramework.h"
#include <vector>
#include <string>
#include <thread>
#include "Logger.h"

QuestionnaireFramework::QuestionnaireFramework(bool anticheatingEnabled, bool isConsole, bool loggerEnabled) {
	if (loggerEnabled) {
		Logger::ActivateLogger();
	}
	if (anticheatingEnabled) {
		std::wstring windowTitle = GetUniqueWindowTitle();
		if (isConsole) {
			SetConsoleTitle((LPCWSTR)windowTitle.c_str());
			Sleep(100);
			m_hook = SetupHook((LPCWSTR)windowTitle.c_str(), L"WindowsHooking.dll", isConsole);
		}
		else {
			//TODO GUI anticheating.
		}
	}
}

void QuestionnaireFramework::LoadQuestions(const std::string& questionTable, const std::string& answerTable) {

	for (auto questionRow : dh->GetTable(questionTable)) {
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
		std::string command = "select * from " + answerTable + " where q_id = " + std::to_string(id);
		std::vector<std::vector<std::string>> answerTable = dh->GetTableFromCommand(command);
		std::vector<Answer> answers;

		for (auto answerRow : answerTable) {
			int id = std::stoi(answerRow[0]);
			std::string text = answerRow[1];
			float percentage = std::stof(answerRow[2]);
			if (std::find_if(answers.begin(), answers.end(), [&text](const Answer& answer) { return answer.GetAnswer() == text; }) == answers.end()) {
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
	dh = new DatabaseHandler(databaseName, databaseHost, databasePort, databaseUser, databasePassword);
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
				m_selectedQuestions.push_back(tempQuestions.at(tempRand));
				tempQuestions.erase(tempQuestions.begin() + tempRand);
				--remainingNumberOfQuestions;
			}
			unchosenQuestions.insert(unchosenQuestions.end(), tempQuestions.begin(), tempQuestions.end());
		}
		else { // Add the entire category when it has less questions than the necessary ammount.
			for (auto question : tempQuestions) {
				m_maximumMark += question.GetPoints();
				m_selectedQuestions.push_back(question);
			}
		}
	}
	// Add randomly chosen questions from the unchosen ones if needed.
	while (m_selectedQuestions.size() < m_numberOfQuestionsNeeded) {
		int tempRand = rand() % unchosenQuestions.size();
		m_maximumMark += unchosenQuestions.at(tempRand).GetPoints();
		m_selectedQuestions.push_back(unchosenQuestions.at(tempRand));
		unchosenQuestions.erase(unchosenQuestions.begin() + tempRand);
	}
}

const std::vector<Question>& QuestionnaireFramework::GetSelectedQuestions()const
{
	return m_selectedQuestions;
}

std::vector<Question>* QuestionnaireFramework::GetSelectedQuestions()
{
	return &m_selectedQuestions;
}

int QuestionnaireFramework::GetMaximumMark()const
{
	return m_maximumMark;
}

void QuestionnaireFramework::SetUser(const std::string& studentTable, const std::string& nameColumn)
{
	std::cin >> m_user;
	std::string command = "insert into "+studentTable+"("+nameColumn+")"+ " values('" + m_user.GetName()+"')";
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
	for (const Question& question : m_selectedQuestions) {
		mark = mark + question.GetAquiredMark();
	}
	percentage = mark / m_maximumMark;
	m_user.SetGrade(10 * percentage);
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

void QuestionnaireFramework::SendResult(const std::string & resultTable, const std::string& gradeColumn, const std::string& studentAnswerTable) const
{
	std::string command="update "+resultTable+" set "+gradeColumn+"="+ std::to_string(m_user.GetGrade())+" where s_id="+ std::to_string(m_user.GetId())+";";
	for (Question question : m_selectedQuestions) {
		if (question.GetQuestionType() == Question::QuestionType::Text) {
			command =command+ "insert into " + studentAnswerTable + " values(" + std::to_string(m_user.GetId()) + ",'" + question.GetGivenTextAnswer() + "'," + std::to_string(question.GetID()) + ");";
		}
		else {
			for (Answer answer : question.GetAnswers()) {
				if (answer.GetSelected()) {
					command = command + "insert into " + studentAnswerTable + " values(" + std::to_string(m_user.GetId()) + ",'" + answer.GetAnswer() + "'," + std::to_string(question.GetID()) + ");";
				}
			}
		}
	}
	dh->RunCommand(command);
}

const HHOOK& QuestionnaireFramework::GetWindowsHook()
{
	return m_hook;
}
