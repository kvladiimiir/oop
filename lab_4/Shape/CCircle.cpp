#include "CCircle.h"

CCircle::CCircle(const CPoint& center, const double radius, const std::string outlineColor, const std::string fillColor)
	: m_center(center)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
	, m_radius(radius)
{
	if (!(radius > 0))
	{
		throw std::logic_error("CCircle error, because radius < 0 or radius = 0");
	}
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

std::string CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CCircle::GetFillColor() const
{
	return m_fillColor;
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return M_PI * 2 * m_radius;
}

std::string CCircle::ToString() const
{
	std::stringstream stream;

	stream << std::fixed << std::setprecision(2);

	stream << "Circle:\ncenter coords: " << GetCenter().GetX() << ' ' << GetCenter().GetY();
	stream << "\nradius: " << GetRadius() << "\narea: " << GetArea() << '\n';
	stream << "perim: " << GetPerimeter() << '\n' << "outlineColor: " << GetOutlineColor() << "\nfillColor: " << GetFillColor();

	return stream.str();
}