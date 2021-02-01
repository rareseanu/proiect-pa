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

void Question::SetQuestionType(const QuestionType& qType)
{
	m_questionType = qType;
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

const float Question::GetAquiredMark() const
{
	float percentage = 0;
	float maxPercentage = 0;
	for (const Answer& answer : m_answers) {
		if (answer.GetSelected()) {
			percentage = percentage + answer.GetPercent();
		}
		if (answer.GetPercent() > 0) {
			maxPercentage += answer.GetPercent();
		}
	}
	if (percentage < 0) {
		percentage = 0;
	}
	return m_points * (percentage / maxPercentage);
}

void Question::GiveAnswer(std::string string)
{
	switch (m_questionType) {
		case QuestionType::Multichoice:
			for (Answer& answer : m_answers) {
				answer.SetSelected(false);
			}
			for (const char& chr : string) {
				if ((size_t)chr - 'a' < m_answers.size() && chr - 'a' >= 0) {
					m_answers[(size_t)chr - 'a'].SetSelected(true);
				}
			}
			break;
		case QuestionType::Text:
		{
			m_givenTextAnswer = string;
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
			break;
		}
		case QuestionType::Singlechoice:
		{
			for (Answer& answer : m_answers) {
				answer.SetSelected(false);
			}
			if (string.size() == 1) {
				if ((size_t)string[0] - 'a' < m_answers.size() && string[0] - 'a' >= 0) {
					m_answers[(size_t)string[0] - 'a'].SetSelected(true);
				}
				break;
			}
		}
	}
}

const std::string& Question::GetGivenTextAnswer() const
{
	return m_givenTextAnswer;
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

const bool Question::GetFlag() const
{
	return m_flagged;
}

const std::string& Question::GetCategory() const
{
	return m_category;
}

const Question::QuestionType Question::GetQuestionType() const
{
	return m_questionType;
}

const Question::QuestionType Question::ConvertStringToQuestionType(const std::string& qType)
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

	throw std::string("The question type entered was invalid. Types allowed: Singlechoice, Multichoice, Text.");
}

const std::string Question::ConvertQuestionTypeToString(const QuestionType& qType)
{
	if (qType == QuestionType::Singlechoice)
		return "Singlechoice";
	else if (qType == QuestionType::Multichoice)
		return "Multichoice";
	else if (qType == QuestionType::Text)
		return "Text";
	return "";
}

std::ostream& operator<<(std::ostream& out, const Question& question)
{
	char answerSymbol = 'a';
	if (question.GetFlag() == true)
		out << "(FLAGGED) ";
	out << question.m_text << '\n';
	if (question.GetAnswers().size() > 1) {
		for (const Answer& a : question.GetAnswers()) {
			out << "\t" << (char)answerSymbol++ << ". " << a << '\n';
		}
	}
	return out;
}
