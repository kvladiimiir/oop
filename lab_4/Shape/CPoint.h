#pragma once
class CPoint
{
public:
	CPoint(double const x, double const y);
	~CPoint() = default;

	double GetX() const;
	double GetY() const;

private:
	double m_x;
	double m_y;
};
