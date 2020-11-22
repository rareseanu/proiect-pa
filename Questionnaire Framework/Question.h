#pragma once
#include<iostream>
#include<vector>
#include "Answer.h"

class Question
{
public:
    Question();
    Question(int id, const std::string& text, int points, const std::string& category, const std::vector<Answer>& answers);
    const std::string& getText() const;
    void setText(const std::string& question);
    const std::vector<Answer>& getAnswers() const;
    void setAnswers(const std::vector<Answer>& answers);
    void readUserAnswer();
    int getPoints();
    bool verifyUserAnswer();
private:
    int m_id;
    std::string m_text;
    std::vector<Answer> m_answers;
    int m_points;
    std::string m_category;
    Answer m_userAnswer;
    std::vector<bool> m_correctlyAnswered;
};

