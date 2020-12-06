#include "TerminalQuestionnaire.h"
#include <string>

TerminalQuestionnaire::TerminalQuestionnaire(int numberOfQuestionsNeeded, int quizTime)
{
	quiz.SetQuizTime(quizTime);
	quiz.SetNumberOfQuestions(numberOfQuestionsNeeded);
	try {
		quiz.OpenDatabase("yufioaba", "ruby.db.elephantsql.com", "5432", "yufioaba", "ZGnmR5rJdvvkXXove7sqUQGNB5-lHNoO");
	}
	catch (std::string error) {
		LOG_ERROR(error);
	}
	srand(time(NULL));
	quiz.LoadQuestions("question", "answer");
	quiz.SelectQuestions(std::vector<std::string> {"SA"});
	m_selectedQuestions = quiz.GetSelectedQuestions();	
}

void TerminalQuestionnaire::Start()
{
	std::cin >> quiz.GetUser();
	std::cin.ignore();
	bool stillHasQuestions = true;
	int currentQuestion = 0;
	quiz.SetTimerFunction(std::bind(&TerminalQuestionnaire::Stop, this));
	quiz.StartTimer();
	for (int i = 0; i < m_selectedQuestions->size() && quiz.CanAnswer(); i++) {
		system("cls");
		std::string string;
		string = "entry";
		while (string == "entry" || string == "\\f" || string == "\\u" || string == "\\b" || string == "\\s") {
			system("cls");
			PrintTimeLeft();
			std::cout << "Number of questions: " << m_selectedQuestions->size(); std::cout << "   Remaining: " << m_selectedQuestions->size() - i << std::endl << std::endl;
			std::cout << "(Category: " << m_selectedQuestions->at(i).GetCategory() <<") (" << m_selectedQuestions->at(i).GetPoints() << "p) " << i + 1 << ". " << m_selectedQuestions->at(i) << '\n';
			std::cout << "(\\b to go back, \\f to flag question, \\u to unflag question, \\s to skip)" << std::endl;
			std::cout << "Answer ";
			if (m_selectedQuestions->at(i).GetAnswers().size() == 1) {
				std::cout << "(text answer): ";
			} 
			else {
				std::cout << "(multichoice): ";
			}
		
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
				m_selectedQuestions->at(i).GiveAnswer(string);
				LOG_INFO("User answered '" + string + "' to question ID " + std::to_string(m_selectedQuestions->at(i).GetID()));
			}
		}
	}

	std::string choice, answer;
	while (choice != "F") {
		system("cls");
		PrintTimeLeft();
		PrintSelectedQuestions();
		std::cout << "Enter the question's number if you want to change its answer or 'F' to finish the quiz: ";
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
				m_selectedQuestions->at(questionNumber).PrintSelected();
			}
		}
		catch (...) {

		}

	}
	if (quiz.CanAnswer()) {
		quiz.StopTimer();
		LOG_INFO("Timer stopped. Remaining time: " + std::to_string(quiz.GetTimer().GetTimeLeft()));
		Stop();
	}
}

void TerminalQuestionnaire::Stop()
{
	//to be replaced with some useful functionality
	std::cout << "Quiz finished" << '\n';
	quiz.CalculateFinalGrade();
	LOG_INFO("Quiz finished. Final grade: " + std::to_string(quiz.GetFinalGrade()));
	quiz.SetCanAnswer(false);
	PrintResults();
	std::cout << "User: " << quiz.GetUser().GetName() << '\n';
	std::cout << "\nFinal grade:" << quiz.GetFinalGrade();
	//quiz.SendResult("student", "nume", "nota");
	exit(0);
}

void TerminalQuestionnaire::PrintAllQuestions() const
{
	int questionSymbol = 1;
	for (auto& category : quiz.GetAllQuestions()) {
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
		questions = quiz.GetQuestionsFromCategory(category);
	}
	catch (std::string error) {
		LOG_ERROR(error);
	}
	std::cout << category << " => \n";
	for (auto& question : questions) {
		std::cout << questionSymbol++ << ". " << question << '\n';
	}
}

void TerminalQuestionnaire::PrintSelectedQuestions() const
{
	int questionSymbol = 0;
	for (auto question : quiz.GetSelectedQuestions()) {
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

void TerminalQuestionnaire::PrintTimeLeft() const
{
	int seconds = quiz.GetTimer().GetTimeLeft() % 60;
	int minutes = (quiz.GetTimer().GetTimeLeft()/60)%60;
	int hours = (quiz.GetTimer().GetTimeLeft() / 60/60)%24;
	std::cout << "Time left: " <<std::setw(2)<< std::setfill('0')<< hours
								<<":"<< std::setw(2)<<std::setfill('0') <<minutes
								<<":"<< std::setw(2)<<seconds << '\n';
}

void TerminalQuestionnaire::PrintResults() const
{
	for (auto& question : quiz.GetSelectedQuestions()) {
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
