#include "QuestionnaireFramework.h"
#include <vector>
#include <string>

void QuestionnaireFramework::loadQuestions() {

	for (auto questionRow : dh->getTable("question")) {
		int id = std::stoi(questionRow[0]);
		std::string text = questionRow[1];
		int points = std::stoi(questionRow[2]);
		std::string category = questionRow[3];
		std::vector<std::vector<std::string>> answerTable = dh->getTableFromCommand("select * from answer where q_id = " + std::to_string(id));
		std::vector<Answer> answers;

		for (auto answerRow : answerTable) {
			int id = std::stoi(answerRow[0]);
			std::string text = answerRow[1];
			float percentage = std::stof(answerRow[2]);

			answers.push_back(Answer(id, text, percentage));
		}
		m_questions[category].push_back(Question(id, text, points, category, answers));
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

void QuestionnaireFramework::printQuestions() const {
	int questionSymbol = 1;
	for (auto& category : m_questions) {
		int answerSymbol = 97; // ASCII(97) = a
		std::cout << category.first << " => ";
		for (auto& question : category.second) {
			std::cout << questionSymbol++ << ". " << question.getText() << '\n';
			for (auto a : question.getAnswers()) {
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
		for (auto a : question.getAnswers()) {
			std::cout << "\t\t" << (char)answerSymbol++ << ". " << a.getAnswer() << '\n';
		}
	}
}


