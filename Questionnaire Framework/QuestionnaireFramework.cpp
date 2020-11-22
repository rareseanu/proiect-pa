#include "QuestionnaireFramework.h"
#include <vector>
#include <string>

QuestionnaireFramework::QuestionnaireFramework(int numberOfQuestionsNeeded)
	: m_numberOfQuestionsNeeded(numberOfQuestionsNeeded), m_maximumMark(0), m_totalNumberOfQuestions(0)
{
	srand(time(NULL));
}

void QuestionnaireFramework::loadQuestions(const std::string& questionTable,const std::string& answerTable) {

	for (auto questionRow : dh->getTable(questionTable)) {
		int id = std::stoi(questionRow[0]);
		std::string text = questionRow[1];
		int points = std::stoi(questionRow[2]);
		std::string category = questionRow[3];
		std::string command= "select * from " + answerTable + " where q_id = " + std::to_string(id);
		std::vector<std::vector<std::string>> answerTable = dh->getTableFromCommand(command);
		std::vector<Answer> answers;

		for (auto answerRow : answerTable) {
			int id = std::stoi(answerRow[0]);
			std::string text = answerRow[1];
			float percentage = std::stof(answerRow[2]);
			if (std::find_if(answers.begin(), answers.end(), [&text](const Answer& answer) { return answer.getAnswer() == text; }) == answers.end()) {
				answers.push_back(Answer(id, text, percentage));
			}
			else {
				std::cout << "\nAnswer aleady existent: "<<text<<std::endl;
			}
		}
		if (answers.empty()) {
			std::cout<<"\nQuestion has no answers: "<< text<<std::endl;
		}
		else {
			m_questions[category].push_back(Question(id, text, points, category, answers));
		}
		++m_totalNumberOfQuestions;
	}
	if (m_totalNumberOfQuestions < m_numberOfQuestionsNeeded) {
		std::cout << "\nWARNING: Not enough questions in the question bank.";
		m_numberOfQuestionsNeeded = m_totalNumberOfQuestions;
	}
}

void QuestionnaireFramework::openDatabase(const std::string& databaseName, const std::string& databaseHost, const std::string& databasePort,
	const  std::string& databaseUser, const std::string& databasePassword)
{
	dh = new DatabaseHandler(databaseName, databaseHost, databasePort, databaseUser, databasePassword);
	if (!dh->isConnected()) {
		throw "Connection to the database failed.";
	}
}

void QuestionnaireFramework::printAllQuestions() const {
	int questionSymbol = 1;
	for (auto& category : m_questions) {
		int answerSymbol = 97; // ASCII(97) = a
		std::cout << category.first << " => ";
		for (auto& question : category.second) {
			std::cout << questionSymbol++ << ". " << question.getText() << '\n';
			for (auto& a : question.getAnswers()) {
				std::cout << "\t\t" << (char)answerSymbol++ << ". " << a.getAnswer() << '\n';
			}
		}
	}
}

const std::vector<Question>& QuestionnaireFramework::getQuestionsFromCategory(const std::string& category) const
{
	auto it = m_questions.find(category);
	if (it != m_questions.end()) {
		return  m_questions.find(category)->second;
	} else {
		throw "There are no questions in the given category (" + category + ").";
	}
}

void QuestionnaireFramework::printQuestionsFromCategory(const std::string& category) const
{
	int questionSymbol = 1;
	std::vector<Question> questions = getQuestionsFromCategory(category);
	int answerSymbol = 97; // ASCII(97) = a
	std::cout << category << " => \n";
	for (auto& question : questions) {
		std::cout << '\t' << questionSymbol++ << ". " << question.getText() << '\n';
		for (auto& a : question.getAnswers()) {
			std::cout << "\t\t" << (char)answerSymbol++ << ". " << a.getAnswer() << '\n';
		}
	}
}

void QuestionnaireFramework::setNumberOfQuestions(int number)
{
	m_numberOfQuestionsNeeded = number;
}

int QuestionnaireFramework::getNumberOfQuestions()
{
	return m_numberOfQuestionsNeeded;
}

void QuestionnaireFramework::selectQuestions(const std::vector<std::string>& categories)
{
	std::vector<Question> unchosenQuestions; //Vector to store remaining unchosen questions from each category.
	for (auto& category : categories) {
		int remainingNumberOfQuestions = m_numberOfQuestionsNeeded / categories.size();
		std::vector<Question> tempQuestions = getQuestionsFromCategory(category);
		// Add random question if the category has more questions than the necessary ammount.
		if (tempQuestions.size() > remainingNumberOfQuestions) { 
			while (remainingNumberOfQuestions != 0) {
				int tempRand = rand() % tempQuestions.size();
				m_maximumMark += tempQuestions.at(tempRand).getPoints();
				m_selectedQuestions.push_back(tempQuestions.at(tempRand));
				tempQuestions.erase(tempQuestions.begin() + tempRand);
				--remainingNumberOfQuestions;
			}
			unchosenQuestions.insert(unchosenQuestions.end(), tempQuestions.begin(), tempQuestions.end());
		}
		else { // Add the entire category when it has less questions than the necessary ammount.
			for (auto question : tempQuestions) {
				m_maximumMark += question.getPoints();
				m_selectedQuestions.push_back(question);
			}
		}
	}
	// Add randomly chosen questions from the unchosen ones if needed.
	while (m_selectedQuestions.size() < m_numberOfQuestionsNeeded) {
		int tempRand = rand() % unchosenQuestions.size();
		m_maximumMark += unchosenQuestions.at(tempRand).getPoints();
		m_selectedQuestions.push_back(unchosenQuestions.at(tempRand));
		unchosenQuestions.erase(unchosenQuestions.begin() + tempRand);
	}
}

void QuestionnaireFramework::printQuestions(const std::vector<Question>& vectorQuestions)
{
	int questionSymbol = 1;
	int answerSymbol = 97; // ASCII(97) = a
	for (auto& question : vectorQuestions) {
		std::cout << '\t' << questionSymbol++ << ". " << question.getText() << '\n';
		for (auto& a : question.getAnswers()) {
			std::cout << "\t\t" << (char)answerSymbol++ << ". " << a.getAnswer() << '\n';
		}
	}
}

const std::vector<Question>& QuestionnaireFramework::getSelectedQuestions()
{
	return m_selectedQuestions;
}

int QuestionnaireFramework::getMaximumMark()
{
	return m_maximumMark;
}




