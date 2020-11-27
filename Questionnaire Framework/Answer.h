#pragma once
#include <iostream>

class Answer
{
public:
	Answer();
	Answer(int id, const std::string& text, float percentage, bool selected);
	void SetPercent(const float&);
	const float GetPercent() const;
	void SetAnswer(const std::string&);
	const std::string& GetAnswer() const;
	void SetId(const int&);
	const int& GetId();
	void SetSelected(const bool&);
	const bool GetSelected() const;
	friend std::istream& operator >>(std::istream&, Answer&);
	friend std::ostream& operator<<(std::ostream& out, const Answer& answer);
private:
	int m_id;
	std::string m_text;
	float m_percentage;
	bool m_selected;
};