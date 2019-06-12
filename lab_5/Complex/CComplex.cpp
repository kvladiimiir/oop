#include "pch.h"
#include "CComplex.h"


CComplex::CComplex(double real, double image)
	: m_real(real)
	, m_image(image)
{
}

double CComplex::Re() const
{
	return m_real;
}

double CComplex::Im() const
{
	return m_image;
}

// возвращает модуль комплексного числа
double CComplex::GetMagnitude() const
{
	return sqrt(pow(m_real, 2) + pow(m_image, 2));
}

// возвращает аргумент комплексного числа
double CComplex::GetArgument() const
{
	if ((m_real == 0.0) || (m_image == 0.0))
	{
		return 0.0;
	}

	return atan2(m_image, m_real);
}

CComplex const CComplex::operator+() const
{
	return CComplex(m_real, m_image);
}

CComplex const CComplex::operator-() const
{
	return CComplex(-m_real, -m_image);
}

CComplex& CComplex::operator+=(const CComplex& complex)
{
	m_real += complex.m_real;
	m_image += complex.m_image;

	return *this;
}

CComplex& CComplex::operator-=(const CComplex& complex)
{
	m_real -= complex.m_real;
	m_image -= complex.m_image;

	return *this;
}

CComplex& CComplex::operator*=(const CComplex& complex)
{
	double copyReal = m_real;

	m_real = m_real * complex.m_real - m_image * complex.m_image;
	m_image = m_image * complex.m_real + copyReal * complex.m_image;

	return *this;
}

CComplex& CComplex::operator/=(const CComplex& complex)
{
	double copyReal = m_real;

	m_real = (m_real * complex.m_real + m_image * complex.m_image) / (pow(complex.m_real, 2) + pow(complex.m_image, 2));
	m_image = (m_image * complex.m_real - copyReal * complex.m_image) / (pow(complex.m_real, 2) + pow(complex.m_image, 2));

	return *this;
}

CComplex const operator+(const CComplex& firstComplex, const CComplex& secondComplex)
{
	return CComplex(firstComplex.Re() + secondComplex.Re(), firstComplex.Im() + secondComplex.Im());
}

CComplex const operator-(const CComplex& firstComplex, const CComplex& secondComplex)
{
	return CComplex(firstComplex.Re() - secondComplex.Re(), firstComplex.Im() - secondComplex.Im());
}

CComplex const operator/(const CComplex& firstComplex, const CComplex& secondComplex)
{
	return CComplex((firstComplex.Re() * secondComplex.Re() + firstComplex.Im() * secondComplex.Im()) / (pow(secondComplex.Re(), 2) + pow(secondComplex.Im(), 2)), (firstComplex.Im() * secondComplex.Re() - firstComplex.Re() * secondComplex.Im()) / (pow(secondComplex.Re(), 2) + pow(secondComplex.Im(), 2)));
}

CComplex const operator*(const CComplex& firstComplex, const CComplex& secondComplex)
{
	return CComplex(firstComplex.Re() * secondComplex.Re() - firstComplex.Im() * secondComplex.Im(), firstComplex.Re() * secondComplex.Im() + firstComplex.Im() * secondComplex.Re());
}

bool operator==(const CComplex& firstComplex, const CComplex& secondComplex)
{
	bool checkReal = (fabs(firstComplex.Re() - secondComplex.Re()) < DBL_EPSILON);
	bool checkImage = (fabs(firstComplex.Im() - secondComplex.Im()) < DBL_EPSILON);
	return checkReal && checkImage;
}

bool operator!=(const CComplex& firstComplex, const CComplex& secondComplex)
{
	return !(firstComplex == secondComplex);
}