#pragma once
#include<iostream>
#include<vector>
#include "Answer.h"

class Question
{
public:
    Question();
    Question(int id, const std::string& text, int points, const std::string& category, const std::vector<Answer>& answers, const bool flagged);
    const std::string& GetText() const;
    const int GetID() const;
    void SetText(const std::string& question);
    const std::vector<Answer>& GetAnswers() const;
    void SetAnswers(const std::vector<Answer>& answers);
    const int GetPoints() const;
    float GetAquiredMark()const;
    bool VerifyUserAnswer();
    void GiveAnswer(const std::string& string);
    void PrintSelected();
    void ResetAnswer();
    void Flag();
    void Unflag();
    bool GetFlag() const;
    friend std::ostream& operator<<(std::ostream& out, const Question& question);
private:
    int m_id = 0;
    std::string m_text;
    std::vector<Answer> m_answers;
    int m_points = 0;
    std::string m_category;
    std::vector<Answer> m_userAnswer;
    bool m_flagged = false;
    std::vector<bool> m_correctlyAnswered;
};

