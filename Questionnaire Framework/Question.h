#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include "Answer.h"

class Question
{
public:
    enum class QuestionType {
        Singlechoice,
        Multichoice,
        Text
    };
    Question();
    Question(int id, const std::string& text, int points, const std::string& category, 
        const std::vector<Answer>& answers, const bool flagged, const QuestionType& type);
    const std::string& GetText() const;
    const int GetID() const;
    void SetText(const std::string& question);
    const std::vector<Answer>& GetAnswers() const;
    void SetAnswers(const std::vector<Answer>& answers);
    const int GetPoints() const;
    float GetAquiredMark()const;
    bool VerifyUserAnswer();
    void GiveAnswer(std::string string);
    void PrintSelected();
    const std::string& GetGivenTextAnswer() const;
    void ResetAnswer();
    void Flag();
    void Unflag();
    bool GetFlag() const;
    std::string GetCategory() const;
    const QuestionType& GetQuestionType();
    friend std::ostream& operator<<(std::ostream& out, const Question& question);

    static QuestionType ConvertStringToQuestionType(const std::string& qType);
    static std::string  ConvertQuestionTypeToString(const QuestionType& qType);
private:
    int m_id = 0;
    std::string m_text;
    std::vector<Answer> m_answers;
    int m_points = 0;
    std::string m_givenTextAnswer;
    std::string m_category;
    QuestionType m_questionType;
    std::vector<Answer> m_userAnswer;
    bool m_flagged = false;
    std::vector<bool> m_correctlyAnswered;
};

