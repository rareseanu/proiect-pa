#include "Answer.h"

Answer::Answer()
{
}

Answer::Answer(int id, const std::string& text, float percent, bool selected)
	:m_id(id), m_text(text), m_percentage(percent), m_selected(selected)
{
}

void Answer::SetPercent(const float& percentage)
{
	this->m_percentage = percentage;
}

const float Answer::GetPercent() const
{
	return m_percentage;
}

void Answer::SetAnswer(const std::string& text)
{
	m_text = text;
}

const std::string& Answer::GetAnswer() const
{
	return m_text;
}

void Answer::SetId(const int& id)
{
	m_id = id;
}

const int& Answer::GetId()
{
	return m_id;
}

void Answer::SetSelected(const bool& selected)
{
	m_selected = selected;
}

const bool Answer::GetSelected() const
{
	return m_selected;
}

std::istream& operator>>(std::istream& in, Answer& answer)
{
	int answerNumber;

	in >> answerNumber;
	answer.SetId(answerNumber);
	answer.SetSelected(true);

	return in;
}

std::ostream& operator<<(std::ostream& out,const Answer& answer)
{
	out <<answer.GetAnswer();
	return out;
}
