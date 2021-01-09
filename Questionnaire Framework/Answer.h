#pragma once
#include <iostream>

class Answer
{
public:
	__declspec(dllexport) Answer();
	__declspec(dllexport) Answer(int id, const std::string& text, float percentage, bool selected);
	__declspec(dllexport) void SetPercent(const float&);
	__declspec(dllexport) const float GetPercent() const;
	__declspec(dllexport) void SetAnswer(const std::string&);
	__declspec(dllexport) const std::string& GetAnswer() const;
	__declspec(dllexport) const int& GetId();
	__declspec(dllexport) void SetSelected(const bool&);
	__declspec(dllexport) const bool GetSelected() const;
	friend __declspec(dllexport) std::ostream& operator<<(std::ostream& out, const Answer& answer);
private:
	int m_id;
	std::string m_text;
	float m_percentage;
	bool m_selected;
};