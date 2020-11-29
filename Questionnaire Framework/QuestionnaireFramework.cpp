#include "QuestionnaireFramework.h"
#include <vector>
#include <string>
#include <thread>
#include "Logger.h"

QuestionnaireFramework::QuestionnaireFramework(int numberOfQuestionsNeeded, int quizTime)
	: m_numberOfQuestionsNeeded(numberOfQuestionsNeeded), m_maximumMark(0), m_totalNumberOfQuestions(0), m_canAnswer(false), m_finalGrade(0), m_quizTime(quizTime)
{
	srand(time(NULL));
}

void QuestionnaireFramework::LoadQuestions(const std::string& questionTable, const std::string& answerTable) {

	for (auto questionRow : dh->GetTable(questionTable)) {
		int id = std::stoi(questionRow[0]);
		std::string text = questionRow[1];
		int points = std::stoi(questionRow[2]);
		std::string category = questionRow[3];
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
			m_questions[category].push_back(Question(id, text, points, category, answers));
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
		throw "Connection to the database failed.";
	}
}

void QuestionnaireFramework::PrintAllQuestions() const {
	int questionSymbol = 1;
	for (auto& category : m_questions) {
		std::cout << category.first << " => ";
		for (auto& question : category.second) {
			std::cout << questionSymbol++ << ". " << question << '\n';
		}
	}
}

const std::vector<Question>& QuestionnaireFramework::GetQuestionsFromCategory(const std::string& category) const
{
	auto it = m_questions.find(category);
	if (it != m_questions.end()) {
		return  m_questions.find(category)->second;
	}
	else {
		throw "There are no questions in the given category (" + category + ").";
	}
}

void QuestionnaireFramework::PrintQuestionsFromCategory(const std::string& category) const
{
	int questionSymbol = 1;
	std::vector<Question> questions;
	try {
		questions = GetQuestionsFromCategory(category);
	}
	catch (std::string error) {
		LOG_ERROR(error);
	}
	std::cout << category << " => \n";
	for (auto& question : questions) {
		std::cout << questionSymbol++ << ". " << question << '\n';
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

void QuestionnaireFramework::SelectQuestions(const std::vector<std::string>& categories)
{
	std::vector<Question> unchosenQuestions; //Vector to store remaining unchosen questions from each category.
	for (auto& category : categories) {
		int remainingNumberOfQuestions = m_numberOfQuestionsNeeded / categories.size();
		std::vector<Question> tempQuestions = GetQuestionsFromCategory(category);
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

void QuestionnaireFramework::PrintSelectedQuestions() const {
	int questionSymbol = 0;
	for (auto question : m_selectedQuestions) {
		std::cout << questionSymbol++ << '.' << question;
		if (question.GetAnswers().empty()) {
			std::cout << "Question unanswered!";
		}
		else {
			std::cout << "Your answers: ";
			question.PrintSelected();
			std::cout << '\n';
		}
	}
}

void QuestionnaireFramework::PrintQuestions(const std::vector<Question>& vectorQuestions)const
{
	int questionSymbol = 1;
	for (auto& question : vectorQuestions) {
		std::cout << questionSymbol++ << ". " << question << '\n';
	}
}

const std::vector<Question>& QuestionnaireFramework::GetSelectedQuestions()const
{
	return m_selectedQuestions;
}

void QuestionnaireFramework::Start()
{
	bool stillHasQuestions = true;
	int currentQuestion = 0;
	Timer timer;
	timer.SetTimeout(std::bind(&QuestionnaireFramework::Stop, this), m_quizTime);
	m_canAnswer = true;
	std::thread timerThread(&Timer::Start, std::ref(timer));
	timerThread.detach();
	for (int i = 0; i < m_selectedQuestions.size() && m_canAnswer; i++) {
		system("cls");
		std::cout << timer.GetTimeLeft() << '\n';
		std::cout << "(" << m_selectedQuestions[i].GetPoints() << "p) " << i + 1 << ". " << m_selectedQuestions[i] << '\n';
		std::string string;
		std::cout << "(\\b to go back)Answer:";
		std::cin >> string;
		if (string == "\\b" && i > 0) {
			i = i - 2;
		}
		else {
			m_selectedQuestions[i].GiveAnswer(string);
		}
	}
	PrintSelectedQuestions();
	std::string choice, answer;
	while (choice != "F") {
		std::cout << "Enter the question's number if you want to change its answer or 'F' to finish the quiz: ";
		std::cin >> choice;
		int questionNumber;
		try {
			questionNumber = std::stoi(choice);
			if (questionNumber >= 0 && questionNumber < m_selectedQuestions.size()) {
				std::cout << '\n' << m_selectedQuestions[questionNumber];
				std::cout << "\nAnswer: ";
				std::cin >> answer;
				m_selectedQuestions[questionNumber].GiveAnswer(answer);
				std::cout << "\nNew answer: ";
				m_selectedQuestions[questionNumber].PrintSelected();
			}
		}
		catch (...) {
			
		}
	}
	if (m_canAnswer) {
		timer.Stop();
		Stop();
	}
}

void QuestionnaireFramework::Stop()
{
	//to be replaced with some useful functionality
	std::cout << "\nQuiz finished" << '\n';
	CalculateFinalGrade();
	m_canAnswer = false;
	std::cout << "Final grade:" << m_finalGrade;
}

int QuestionnaireFramework::GetMaximumMark()const
{
	return m_maximumMark;
}

void QuestionnaireFramework::CalculateFinalGrade()
{
	float percentage;
	float mark = 0;
	for (const Question& question : m_selectedQuestions) {
		mark = mark + question.GetAquiredMark();
	}
	percentage = mark / m_maximumMark;
	m_finalGrade = 10 * percentage;
}

float QuestionnaireFramework::GetFinalGrade() const
{
	return m_finalGrade;
}




