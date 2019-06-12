#include "CRectangle.h"

CRectangle::CRectangle(const CPoint& leftTop, const double width, const double height, const std::string outlineColor, const std::string fillColor)
	: m_height(height)
	, m_leftTop(leftTop)
	, m_width(width)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
	if (!(width > 0))
	{
		throw std::logic_error("Rectangle error, because width < 0 or width = 0.");
	}

	if (!(height > 0))
	{
		throw std::logic_error("Rectangle error, because height < 0 or height = 0.");
	}
}

double CRectangle::GetPerimeter() const
{
	return 2 * (m_height + m_width);
}

double CRectangle::GetArea() const
{
	return m_height * m_width;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

std::string CRectangle::GetFillColor() const
{
	return m_fillColor;
}

std::string CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

CPoint CRectangle::GetRightBottom() const
{
	CPoint rightBottom(m_leftTop.GetX() + m_width, m_leftTop.GetY() - m_height);
	return rightBottom;
}

std::string CRectangle::ToString() const
{
	std::stringstream stream;

	stream << std::fixed << std::setprecision(2);

	stream << "Rectangle:\nWidth: " << GetWidth() << " Height" << GetHeight() << '\n';
	stream << "Left top point: x - " << GetLeftTop().GetX() << " y - " << GetLeftTop().GetY() << '\n';
	stream << "Right bottom point: x - " << GetRightBottom().GetX() << " y - " << GetRightBottom().GetY() << '\n';
	stream << "perim: " << GetPerimeter() << "\narea: " << GetArea() << '\n';
	stream << "outlineColor: " << GetOutlineColor() << "\nfillColor: " << GetFillColor();

	return stream.str();
}
