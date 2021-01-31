#include "User.h"
#include <sstream>
#include <string>

User::User()
{
}

int User::GetId() const
{
	return m_id;
}

const std::string User::GetName() const
{
	std::stringstream ss;
	ss << m_firstName << " " << m_lastName;

	return ss.str();
}

const std::string& User::GetFirstName() const
{
	return m_firstName;
}

void User::SetFirstName(const std::string& firstName)
{
	m_firstName = firstName;
}

const std::string& User::GetLastName() const
{
	return m_lastName;
}

void User::SetLastName(const std::string& lastName)
{
	m_lastName = lastName;
}

float User::GetGrade() const
{
	return m_grade;
}

void User::SetGrade(float grade)
{
	m_grade = grade;
}

void User::SetId(int id) {
	m_id = id;
}

std::istream& operator>>(std::istream& in, User& user)
{
	std::cout << "First name:";
	in >> user.m_firstName;
	std::cout << "Last name:";
	in >> user.m_lastName;
	return in;
}
