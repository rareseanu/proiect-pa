#include "Answer.h"

Answer::Answer()
{
}

Answer::Answer(int id, const std::string& text, float percent)
	:m_id(id), m_text(text), m_percentage(percent)
{
}

void Answer::setPercent(const float& percentage)
{
	this->m_percentage = percentage;
}

const float Answer::getPercent() const
{
	return m_percentage;
}

void Answer::setAnswer(const std::string& text)
{
	m_text = text;
}

const std::string& Answer::getAnswer() const
{
	return m_text;
}

std::istream& operator>>(std::istream& in, Answer& answer)
{
	int answerNumber;

	in >> answerNumber;
	answer.setId(answerNumber);

	return in;
}
