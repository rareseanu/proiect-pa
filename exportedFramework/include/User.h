#pragma once
#include <iostream>

class __declspec(dllexport) User
{
public:
	User();
	int GetId() const;
	std::string GetName() const;
	std::string GetFirstName() const;
	void SetFirstName(std::string firstName);
	std::string GetLastName() const;
	void SetLastName(std::string lastName);
	float GetGrade() const;
	void SetGrade(float);
	void SetId(int id);
	friend __declspec(dllexport) std::istream& operator>>(std::istream& in, User& user);
private:
	int m_id = 0;
	std::string m_firstName;
	std::string m_lastName;
	float m_grade = 0;
};

