#pragma once
#include <iostream>

class Answer
{
public:
	Answer();
	Answer(int id, const std::string& text, float percentage);
	void setPercent(const float&);
	const float getPercent() const;
	void setAnswer(const std::string&);
	const std::string& getAnswer() const;
private:
	int m_id;
	std::string m_text;
	float m_percentage;
};