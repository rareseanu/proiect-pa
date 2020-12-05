#include "Question.h"

Question::Question()
{
}

Question::Question(int id, const std::string& text, int points, const std::string& category, const std::vector<Answer>& answers, const bool flagged)
	: m_id(id), m_text(text), m_points(points), m_category(category), m_answers(answers), m_flagged(flagged)
{
}

const std::string& Question::GetText() const
{
	return m_text;
}

const int Question::GetID() const
{
	return m_id;
}

void Question::SetText(const std::string& text)
{
	m_text = text;
}

const std::vector<Answer>& Question::GetAnswers() const
{
	return m_answers;
}

void Question::SetAnswers(const std::vector<Answer>& answers)
{
	m_answers = answers;
}

const int Question::GetPoints() const
{
	return m_points;
}

float Question::GetAquiredMark()const
{
	float percentage = 0;
	for (Answer answer : m_answers) {
		if (answer.GetSelected()) {
			percentage = percentage + answer.GetPercent();
		}
	}
	if (percentage < 0) {
		percentage = 0;
	}
	return m_points * (percentage / 100);
}

bool Question::VerifyUserAnswer()
{
	std::vector<bool> shouldBeTrue;
	for (auto currentAnswer : m_answers)
	{
		for (int indexUserAnswer = 0; indexUserAnswer < m_userAnswer.size(); indexUserAnswer++)
		{
			if (m_userAnswer[indexUserAnswer].GetId() == currentAnswer.GetId())
			{
				shouldBeTrue[currentAnswer.GetId()] = true;

				if (currentAnswer.GetPercent() > 0)
				{
					m_correctlyAnswered[m_userAnswer[indexUserAnswer].GetId()] = true;
				}
				else
				{
					m_correctlyAnswered[m_userAnswer[indexUserAnswer].GetId()] = false;
				}
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

void Question::GiveAnswer(const std::string& string)
{
	for (Answer& answer : m_answers) {
		answer.SetSelected(false);
	}
	for (const char& chr : string) {
		if (chr - 'a' < m_answers.size() && chr - 'a' >= 0) {
			m_answers[chr - 'a'].SetSelected(true);
		}
	}
}

void Question::PrintSelected() {
	for (const Answer& answer : m_answers) {
		if (answer.GetSelected())
			std::cout << answer << " ";
	}
	std::cout << '\n';
}

void Question::ResetAnswer()
{
	m_userAnswer.clear();
}

void Question::Flag()
{
	m_flagged = true;
}

void Question::Unflag()
{
	m_flagged = false;
}

bool Question::GetFlag() const
{
	return m_flagged;
}

std::ostream& operator<<(std::ostream& out, const Question& question)
{
	char answerSymbol = 'a';
	if (question.GetFlag() == true)
		out << "(FLAGGED) ";
	out << question.m_text << '\n';
	for (auto& a : question.GetAnswers()) {
		out << "\t" << (char)answerSymbol++ << ". " << a << '\n';
	}
	return out;
}
