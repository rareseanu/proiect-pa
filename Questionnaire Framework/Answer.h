#pragma once
#include <iostream>

class Answer
{
public:
	Answer();
	Answer(int id, const std::string& text, float percentage, bool selected);
	void setPercent(const float&);
	const float getPercent() const;
	void setAnswer(const std::string&);
	const std::string& getAnswer() const;
	void setId(const int&);
	const int& getId();
	void setSelected(const bool&);
	const bool getSelected() const;
	friend std::istream& operator >>(std::istream&, Answer&);
private:
	int m_id;
	std::string m_text;
	float m_percentage;
	bool m_selected;
};