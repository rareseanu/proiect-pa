#include "TerminalQuestionnaire.h"
#include "Logger.h"

TerminalQuestionnaire::TerminalQuestionnaire(int numberOfQuestionsNeeded, int m_quizTime)
{
	m_quiz.SetQuizTime(m_quizTime);
	m_quiz.SetNumberOfQuestions(numberOfQuestionsNeeded);
	try {
		m_quiz.OpenDatabase("yufioaba", "ruby.db.elephantsql.com", "5432", "yufioaba", "ZGnmR5rJdvvkXXove7sqUQGNB5-lHNoO");
	}
	catch (std::string error) {
		std::cout << error;
		LOG_ERROR(error);
		exit(0);
	}
	srand(time(NULL));
	m_quiz.SetQuestionsTable("question", "q_id", "text", "points", "category", "type");
	m_quiz.SetAnswersTable("answer", "a_id", "text", "percentage", "q_id");
	m_quiz.SetUserAnswerTable("student_raspuns", "s_id", "raspuns", "q_id");
	m_quiz.LoadQuestions();
	m_quiz.SelectQuestions(std::vector<std::string> {"SA", "mate"});
	m_selectedQuestions = m_quiz.GetSelectedQuestions();
	m_quiz.SetMaximumGrade(100);
}

void TerminalQuestionnaire::Start()
{
	m_quiz.SetUser("student", "nume", "time_start");
	m_quiz.SetupAnticheating(L"Questionnaire");
	std::cin.ignore();
	bool stillHasQuestions = true;
	int currentQuestion = 0;
	m_quiz.SetTimerFunction(std::bind(&TerminalQuestionnaire::Stop, this));
	m_quiz.StartTimer();
	for (int i = 0; i < m_selectedQuestions->size() && m_quiz.CanAnswer(); i++) {
		system("cls");
		if (m_quiz.CheatingDetected()) {
			break;
		}
		std::string string;
		string = "entry";
		while (string == "entry" || string == "\\f" || string == "\\u" || string == "\\b" || string == "\\s") {
			system("cls");
			PrintTimeLeft();
			std::cout << "Number of questions: " << m_selectedQuestions->size(); std::cout << "   Remaining: " << m_selectedQuestions->size() - i << std::endl << std::endl;
			std::cout << "(Category: " << m_selectedQuestions->at(i).GetCategory() << ") (" << m_selectedQuestions->at(i).GetPoints() << "p) " << i + 1 << ". " << m_selectedQuestions->at(i) << '\n';
			std::cout << "(\\b to go back, \\f to flag question, \\u to unflag question, \\s to skip)" << std::endl;
			std::cout << "Answer ";
			std::cout << "(" + Question::ConvertQuestionTypeToString(m_selectedQuestions->at(i).GetQuestionType()) + ")";

			std::getline(std::cin, string);
			if (string == "\\b" && i > 0) {
				LOG_INFO("User went back to question ID " + std::to_string(m_selectedQuestions->at(i).GetID()));
				i--;
			}
			else if (string == "\\f") {
				m_selectedQuestions->at(i).Flag();
				LOG_INFO("User flagged question ID " + std::to_string(m_selectedQuestions->at(i).GetID()));
			}
			else if (string == "\\u") {
				m_selectedQuestions->at(i).Unflag();
				LOG_INFO("User unflagged question ID " + std::to_string(m_selectedQuestions->at(i).GetID()));
			}
			else if (string == "\\s") {
				m_selectedQuestions->push_back(m_selectedQuestions->at(i));
				for (int index = i; index < m_selectedQuestions->size() - 1; index++) {
					m_selectedQuestions->at(index) = m_selectedQuestions->at(index + 1);
				}
				m_selectedQuestions->pop_back();

				LOG_INFO("User skipped question ID " + std::to_string(m_selectedQuestions->at(i).GetID()));
			}
			else {
				try {
					m_selectedQuestions->at(i).GiveAnswer(string);
					LOG_INFO("User answered '" + string + "' to question ID " + std::to_string(m_selectedQuestions->at(i).GetID()));
				}
				catch (std::string error) {
					string = "entry";
				}
			}
		}
	}

	std::string choice, answer;
	while (choice != "F") {
		system("cls");
		if (m_quiz.CheatingDetected()) {
			break;
		}
		PrintTimeLeft();
		PrintSelectedQuestions();
		std::cout << "Enter the question's number if you want to change its answer or 'F' to finish the m_quiz: ";
		std::cin >> choice;
		int questionNumber;
		system("cls");
		try {
			questionNumber = std::stoi(choice);
			if (questionNumber >= 0 && questionNumber < m_selectedQuestions->size()) {
				answer = "entry";
				while (answer == "entry" || answer == "\\f" || answer == "\\u") {
					system("cls");
					PrintTimeLeft();
					std::cout << '\n' << m_selectedQuestions->at(questionNumber);
					std::cout << "\n(\\f to flag question, \\u to unflag question, \\c to clear your answer)" << std::endl;
					std::cout << "\nAnswer: ";
					std::cin.ignore();
					std::getline(std::cin, answer);
					if (answer == "\\f") {
						m_selectedQuestions->at(questionNumber).Flag();
						LOG_INFO("User flagged question ID " + std::to_string(m_selectedQuestions->at(questionNumber).GetID()));
					}
					else if (answer == "\\u") {
						m_selectedQuestions->at(questionNumber).Unflag();
						LOG_INFO("User unflagged question ID " + std::to_string(m_selectedQuestions->at(questionNumber).GetID()));
					}
					else if (answer == "\\c") {
						m_selectedQuestions->at(questionNumber).ResetAnswer();
						LOG_INFO("User cleared his answer on question ID " + std::to_string(m_selectedQuestions->at(questionNumber).GetID()));
					}
				}
				LOG_INFO("User changed answer for question ID: " + std::to_string(m_selectedQuestions->at(questionNumber).GetID())
					+ ". New answer: " + answer);
				m_selectedQuestions->at(questionNumber).GiveAnswer(answer);

				std::cout << "\nNew answer: ";
				PrintSelectedAnswers(m_selectedQuestions->at(questionNumber));
			}
		}
		catch (...) {

		}

	}
	if (m_quiz.CanAnswer()) {
		m_quiz.StopTimer();
		LOG_INFO("Timer stopped. Remaining time: " + std::to_string(m_quiz.GetTimer().GetTimeLeft()));
		Stop();
	}
}

void TerminalQuestionnaire::Stop()
{
	m_quiz.CalculateFinalGrade();
	LOG_INFO("m_quiz finished. Final grade: " + std::to_string(m_quiz.GetFinalGrade()));
	m_quiz.SetCanAnswer(false);
	if (m_quiz.CheatingDetected()) {
		m_quiz.GetUser().SetGrade(m_quiz.GetDefaultGrade());
	}
	PrintResults();
	std::cout << "User: " << m_quiz.GetUser().GetName() << '\n';
	std::cout << "\nFinal grade:" << m_quiz.GetFinalGrade();
	m_quiz.SendResult("student", "nota", "time_end");
	if (m_quiz.GetWindowsHook() != NULL) {
		UnhookWindowsHookEx(m_quiz.GetWindowsHook());
	}
	system("pause");
	exit(0);
}

void TerminalQuestionnaire::PrintAllQuestions() const
{
	int questionSymbol = 1;
	for (auto& category : m_quiz.GetAllQuestions()) {
		std::cout << category.first << " => ";
		for (auto& question : category.second) {
			std::cout << questionSymbol++ << ". " << question << '\n';
		}
	}
}

void TerminalQuestionnaire::PrintQuestionsFromCategory(const std::string& category) const
{
	int questionSymbol = 1;
	std::vector<Question> questions;
	try {
		questions = m_quiz.GetQuestionsFromCategory(category);
	}
	catch (std::string error) {
		LOG_ERROR(error);
	}
	std::cout << category << " => \n";
	for (auto& question : questions) {
		std::cout << questionSymbol++ << ". " << question << '\n';
	}
}

void TerminalQuestionnaire::PrintSelectedAnswers(const Question& question) const {
	std::vector<Answer> answers = question.GetAnswers();
	if (answers.size() > 1) {
		for (const Answer& answer : answers) {
			if (answer.GetSelected())
				std::cout << answer << " ";
		}
	}
	else {
		std::cout << question.GetGivenTextAnswer();
	}
	std::cout << '\n';
}

void TerminalQuestionnaire::PrintSelectedQuestions() const
{
	int questionSymbol = 0;
	
	for (const Question& question : *(m_selectedQuestions)) {
		std::cout << questionSymbol++ << '.' << question;
		if (question.GetAnswers().empty()) {
			std::cout << "Question unanswered!";
		}
		else {
			std::cout << "Your answers: ";
			PrintSelectedAnswers(question);
			std::cout << '\n';
		}
	}
}

void TerminalQuestionnaire::PrintTimeLeft() const
{
	int seconds = m_quiz.GetTimer().GetTimeLeft() % 60;
	int minutes = (m_quiz.GetTimer().GetTimeLeft() / 60) % 60;
	int hours = (m_quiz.GetTimer().GetTimeLeft() / 60 / 60) % 24;
	std::cout << "Time left: " << std::setw(2) << std::setfill('0') << hours
		<< ":" << std::setw(2) << std::setfill('0') << minutes
		<< ":" << std::setw(2) << seconds << '\n';
}

void TerminalQuestionnaire::PrintResults() const
{
	for (auto& question : *(m_selectedQuestions)) {
		std::cout << question.GetText() << " Marks: " << question.GetAquiredMark()
			<< '/' << question.GetPoints() << '\n';
		for (auto& answer : question.GetAnswers()) {
			std::string temp = answer.GetAnswer();
			if (answer.GetPercent() > 0) {
				temp += "(correct)";
			}
			else {
				temp += "(wrong)";
			}
			if (answer.GetSelected()) {
				temp += +"(chosen)";
			}
			std::cout << '\t' << temp << '\n';
		}
	}
}
