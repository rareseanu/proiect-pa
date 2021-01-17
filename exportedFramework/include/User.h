#pragma once
#include <iostream>

class User
{
public:
	__declspec(dllexport) User();
	__declspec(dllexport) int GetId() const;
	__declspec(dllexport) std::string GetName() const;
	__declspec(dllexport) std::string GetFirstName() const;
	__declspec(dllexport) void SetFirstName(std::string firstName);
	__declspec(dllexport) std::string GetLastName() const;
	__declspec(dllexport) void SetLastName(std::string lastName);
	__declspec(dllexport) float GetGrade() const;
	__declspec(dllexport) void SetGrade(float);
	__declspec(dllexport) void SetId(int id);
	friend __declspec(dllexport) std::istream& operator>>(std::istream& in, User& user);
private:
	int m_id = 0;
	std::string m_firstName;
	std::string m_lastName;
	float m_grade = 0;
};
