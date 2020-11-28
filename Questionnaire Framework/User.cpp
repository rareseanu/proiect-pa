#include "User.h"
#include <sstream>
#include <string>

User::User()
{
}

User::User(int id, std::string firstName, std::string lastName, Mark mark)
	 :m_id(id), m_firstName(firstName), m_lastName(lastName), m_mark(mark)
{
}

int User::getId() const
{
	return m_id;
}

std::string User::getName() const
{
	std::stringstream ss;
	ss << m_firstName << " " << m_lastName;

	return ss.str();
}

std::string User::getFirstName() const
{
	return m_firstName;
}

std::string User::getLastName() const
{
	return m_lastName;
}

Mark User::getMark() const
{
	return m_mark;
}

void User::setMark(Mark mark)
{
	m_mark = mark;
}
