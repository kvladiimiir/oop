#pragma once
#include <cmath>
#include <sstream>

class CComplex
{
public:
	CComplex(double real = 0, double image = 0);
	// возвращает действительную часть комплексного числа
	double Re() const;
	// возвращает мнимую часть комплексного числа
	double Im() const;
	// возвращает модуль комплексного числа
	double GetMagnitude() const;
	// возвращает аргумент комплексного числа
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
