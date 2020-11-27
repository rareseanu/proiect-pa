#pragma once
#include<iostream>
#include<vector>
#include "Answer.h"

class Question
{
public:
    Question();
    Question(int id, const std::string& text, int points, const std::string& category, const std::vector<Answer>& answers);
    const std::string& GetText() const;
    void SetText(const std::string& question);
    const std::vector<Answer>& GetAnswers() const;
    void SetAnswers(const std::vector<Answer>& answers);
    void ReadUserAnswer();
    int GetPoints();
    float GetAquiredMark()const;
    bool VerifyUserAnswer();
    void GiveAnswer();
    friend std::ostream& operator<<(std::ostream& out, const Question& question);
private:
    int m_id;
    std::string m_text;
    std::vector<Answer> m_answers;
    int m_points;
    std::string m_category;
    Answer m_userAnswer;
    std::vector<bool> m_correctlyAnswered;
};

