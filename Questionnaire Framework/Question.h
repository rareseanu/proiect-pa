#pragma once
#include<iostream>
#include<vector>

class Question
{
public:
    Question();
    Question(const std::string& question, const std::vector<std::string>& answers,bool multichoice);
    const std::string& getQuestion();
    void setQuestion(const std::string& question);
    const std::vector<std::string>& getAnswers();
    void setAnswers(const std::vector<std::string> &answers);
    bool isMultichoice();
    bool setMultichoice(bool multichoice);
private:
    bool multichoice;
    std::string question;
    std::vector<std::string> answers;
};

