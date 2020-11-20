#include "Question.h"

Question::Question()
{
}

Question::Question(int id, const std::string& text, int points, const std::string& category, const std::vector<Answer>& answers)
	: m_id(id), m_text(text), m_points(points), m_category(category), m_answers(answers)
{
}

const std::string& Question::getText() const
{
	return m_text;
}

void Question::setText(const std::string& text)
{
	m_text = text;
}

const std::vector<Answer>& Question::getAnswers() const
{
	return m_answers;
}

void Question::setAnswers(const std::vector<Answer> &answers)
{
	m_answers = answers;
}
