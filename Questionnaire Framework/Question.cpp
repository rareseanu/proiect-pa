#include "Question.h"

Question::Question()
{
}

Question::Question(const std::string& question, const std::vector<std::string>& answers, bool multichoice)
{
	this->question = question;
	this->answers = answers;
	this->multichoice = multichoice;
}

const std::string& Question::getQuestion()
{
	return question;
}

void Question::setQuestion(const std::string& question)
{
	this->question = question;
}

const std::vector<std::string>& Question::getAnswers()
{
	return answers;
}

void Question::setAnswers(const std::vector<std::string> &answers)
{
	this->answers = answers;
}

bool Question::isMultichoice()
{
	return false;
}

bool Question::setMultichoice(bool multichoice)
{
	return false;
}
