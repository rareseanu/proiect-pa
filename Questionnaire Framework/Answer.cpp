#include "Answer.h"

Answer::Answer()
{
}

Answer::Answer(const std::string answer, float percent)
{
	this->answer = answer;
	this->percent = percent;
}

void Answer::setPercent(const float& percent)
{
	this->percent = percent;
}

const float Answer::getPercent()
{
	return percent;
}

void Answer::makeCorrect()
{
	correct = true;
}

void Answer::makeIncorrect()
{
	correct = false;
}

bool Answer::isCorrect()
{
	return correct;
}

void Answer::setAnswer(const std::string& answer)
{
	this->answer = answer;
}

const std::string Answer::getAnswer()
{
	return answer;
}
