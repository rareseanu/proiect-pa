#pragma once
#include <iostream>

class Answer
{
public:
	Answer();
	Answer(const std::string, float);
	void setPercent(const float&);
	const float getPercent();
	void makeCorrect();
	void makeIncorrect();
	bool isCorrect();
	void setAnswer(const std::string&);
	const std::string getAnswer();
private:
	std::string answer;
	float percent;
	bool correct;
};