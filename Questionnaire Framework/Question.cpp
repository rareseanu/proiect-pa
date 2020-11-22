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

void Question::readUserAnswer()
{
	std::cin >> m_userAnswer;
}

int Question::getPoints()
{
	return m_points;
}

bool Question::verifyUserAnswer()
{
	std::vector<bool> shouldBeTrue;
	for (auto currentAnswer : m_answers)
	{
		if (m_userAnswer.getId() == currentAnswer.getId())
		{
			shouldBeTrue[currentAnswer.getId()] = true;

			if (currentAnswer.getPercent() > 0)
			{
				m_correctlyAnswered[m_userAnswer.getId()] = true;
			}
			else
			{
				m_correctlyAnswered[m_userAnswer.getId()] = false;
			}
		}
	}

	bool fullyCorrect = true;
	for (int index = 0; index < m_answers.size(); index++)
	{
		if (shouldBeTrue[index] == true && m_correctlyAnswered[index] == false)
			fullyCorrect = false;
	}

	return fullyCorrect;
}
