#pragma once
#include <cmath>
#include <sstream>

class CComplex
{
public:
	CComplex(double real = 0, double image = 0);
	// ���������� �������������� ����� ������������ �����
	double Re() const;
	// ���������� ������ ����� ������������ �����
	double Im() const;
	// ���������� ������ ������������ �����
	double GetMagnitude() const;
	// ���������� �������� ������������ �����
	double GetArgument() const;

	CComplex const operator+() const;
	CComplex const operator-() const;
	CComplex& operator+=(const CComplex& complex);
	CComplex& operator-=(const CComplex& complex);
	CComplex& operator*=(const CComplex& complex);
	CComplex& operator/=(const CComplex& complex);

private:
	double m_real;
	double m_image;
};

CComplex const operator+(const CComplex& firstComplex, const CComplex& secondComplex);
CComplex const operator-(const CComplex& firstComplex, const CComplex& secondComplex);
CComplex const operator/(const CComplex& firstComplex, const CComplex& secondComplex);
CComplex const operator*(const CComplex& firstComplex, const CComplex& secondComplex);
bool operator==(const CComplex& firstComplex, const CComplex& secondComplex);
bool operator!=(const CComplex& firstComplex, const CComplex& secondComplex);
