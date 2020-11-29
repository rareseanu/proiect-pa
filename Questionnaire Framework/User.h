#pragma once
#include "Mark.h"
#include <iostream>

class User
{
public:
	User();
	User(int, std::string, std::string, float);
	int GetId() const;
	std::string GetName() const;
	std::string GetFirstName() const;
	void SetFirstName(std::string firstName);
	std::string GetLastName() const;
	void SetLastName(std::string lastName);
	float GetMark() const;
	void SetMark(float);
	friend std::istream& operator>>(std::istream& in, User& user);
private:
	int m_id;
	std::string m_firstName;
	std::string m_lastName;
	float m_grade;
};

