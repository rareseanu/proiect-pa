#pragma once
#include "Mark.h"
#include <iostream>

class User
{
public:
	User();
	User(int, std::string, std::string, Mark);
	int getId() const;
	std::string getName() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	Mark getMark() const;
	void setMark(Mark);

private:
	int m_id;
	std::string m_firstName;
	std::string m_lastName;
	Mark m_mark;
};

