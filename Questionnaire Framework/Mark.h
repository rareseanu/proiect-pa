#pragma once
class Mark
{
public:
	Mark();
	Mark(float);
	const float getMark() const;
	void setMark(const float&);
	void addToMark(const float&);

private:
	float m_mark;
	bool m_passed;
};

