#include "Question.h"

Question::Question()
{
}

Question::Question(int id, const std::string& text, int points, const std::string& category, 
				   const std::vector<Answer>& answers, const bool flagged, const QuestionType& qType)
	: m_id(id), m_text(text), m_points(points), m_category(category), m_answers(answers), m_flagged(flagged), m_questionType(qType)
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

void Question::GiveAnswer(std::string string)
{
	if (m_answers.size() > 1) {
		for (Answer& answer : m_answers) {
			answer.SetSelected(false);
		}
		for (const char& chr : string) {
			if (chr - 'a' < m_answers.size() && chr - 'a' >= 0) {
				m_answers[chr - 'a'].SetSelected(true);
			}
		}
	}
	else {
		std::string temp = m_answers[0].GetAnswer();
		temp.erase(std::remove_if(temp.begin(), temp.end(), isspace), temp.end());
		string.erase(std::remove_if(string.begin(), string.end(), isspace), string.end());
		std::transform(temp.begin(), temp.end(), temp.begin(),
			[](unsigned char c) { return tolower(c); });
		std::transform(string.begin(), string.end(), string.begin(),
			[](unsigned char c) { return tolower(c); });
		if (temp == string) {
			m_answers[0].SetSelected(true);
		}
		m_givenTextAnswer = string;
	}
}

void Question::PrintSelected() {
	if (m_answers.size() > 1) {
		for (const Answer& answer : m_answers) {
			if (answer.GetSelected())
				std::cout << answer << " ";
		}
	}
	else {
		std::cout << m_givenTextAnswer;
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

std::string Question::GetCategory() const
{
	return m_category;
}

const Question::QuestionType& Question::GetQuestionType()
{
	return m_questionType;
}

Question::QuestionType Question::ConvertStringToQuestionType(const std::string& qType)
{
	std::string temporary = qType;
	std::transform(temporary.begin(), temporary.end(), temporary.begin(),
		[](unsigned char c) { return tolower(c); });
	if (temporary == "singlechoice")
		return QuestionType::Singlechoice;
	else if (temporary == "multichoice")
		return QuestionType::Multichoice;
	else if (temporary == "text")
		return QuestionType::Text;

	throw "The question type entered was invalid. Types allowed: Singlechoice, Multichoice, Text.";
}

std::string Question::ConvertQuestionTypeToString(const QuestionType& qType)
{
	if (qType == QuestionType::Singlechoice)
		return "Singlechoice";
	else if (qType == QuestionType::Multichoice)
		return "Multichoice";
	else if (qType == QuestionType::Text)
		return "Text";
}

std::ostream& operator<<(std::ostream& out, const Question& question)
{
	char answerSymbol = 'a';
	if (question.GetFlag() == true)
		out << "(FLAGGED) ";
	out << question.m_text << '\n';
	if (question.GetAnswers().size() > 1) {
		for (auto& a : question.GetAnswers()) {
			out << "\t" << (char)answerSymbol++ << ". " << a << '\n';
		}
	}
	return out;
}
