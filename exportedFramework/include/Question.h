#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include "Answer.h"

class  Question
{
public:
	enum class QuestionType {
		Singlechoice,
		Multichoice,
		Text
	};

	__declspec(dllexport) static const QuestionType ConvertStringToQuestionType(const std::string& qType);
	__declspec(dllexport) static const std::string ConvertQuestionTypeToString(const QuestionType& qType);

	__declspec(dllexport) Question();
	__declspec(dllexport) Question(int id, const std::string& text, int points, const std::string& category,
		const std::vector<Answer>& answers, const bool flagged, const QuestionType& type);

	__declspec(dllexport) const int GetID() const;
	__declspec(dllexport) const int GetPoints() const;
	__declspec(dllexport) const float GetAquiredMark() const;
	__declspec(dllexport) const bool GetFlag() const;
	__declspec(dllexport) const QuestionType GetQuestionType() const;
	__declspec(dllexport) const std::vector<Answer>& GetAnswers() const;
	__declspec(dllexport) const std::string& GetGivenTextAnswer() const;
	__declspec(dllexport) const std::string& GetCategory() const;
	__declspec(dllexport) const std::string& GetText() const;

	__declspec(dllexport) void SetText(const std::string& question);
	__declspec(dllexport) void SetQuestionType(const QuestionType& qType);
	__declspec(dllexport) void SetAnswers(const std::vector<Answer>& answers);
	__declspec(dllexport) bool VerifyUserAnswer();

	__declspec(dllexport) void GiveAnswer(std::string string);

	__declspec(dllexport) void ResetAnswer();
	__declspec(dllexport) void Flag();
	__declspec(dllexport) void Unflag();

	friend __declspec(dllexport) std::ostream& operator<<(std::ostream& out, const Question& question);

private:
	QuestionType m_questionType;
	std::string m_text;
	std::string m_givenTextAnswer;
	std::string m_category;
	int m_id = 0;
	int m_points = 0;
	bool m_flagged = false;
	std::vector<Answer> m_answers;
	std::vector<Answer> m_userAnswer;
	std::vector<bool> m_correctlyAnswered;
};

