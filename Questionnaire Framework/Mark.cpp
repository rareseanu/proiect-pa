#include "Mark.h"

Mark::Mark()
{
	m_mark = 1.00;
	m_passed = false;
}

Mark::Mark(float mark)
{
	m_mark = mark;
	if (mark >= 5)
		m_passed = true;
	else
		m_passed = false;
}

const float Mark::getMark() const
{
	return m_mark;
}

void Mark::setMark(const float& mark)
{
	m_mark = mark;
	if (mark >= 5)
		m_passed = true;
	else
		m_passed = false;
}

void Mark::addToMark(const float& points)
{
	m_mark += points;
	if (m_mark >= 5)
		m_passed = true;
}
