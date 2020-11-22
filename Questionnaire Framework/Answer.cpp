#include "Answer.h"

Answer::Answer()
{
}

Answer::Answer(int id, const std::string& text, float percent, bool selected)
	:m_id(id), m_text(text), m_percentage(percent), m_selected(selected)
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

void Answer::setId(const int& id)
{
	m_id = id;
}

const int& Answer::getId()
{
	return m_id;
}

void Answer::setSelected(const bool& selected)
{
	m_selected = selected;
}

const bool Answer::getSelected() const
{
	return m_selected;
}

std::istream& operator>>(std::istream& in, Answer& answer)
{
	int answerNumber;

	in >> answerNumber;
	answer.setId(answerNumber);
	answer.setSelected(true);

	return in;
}
