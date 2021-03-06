#pragma once
#include <string>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <sstream>

class IShape
{
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string GetOutlineColor() const = 0;
	virtual std::string ToString() const = 0;
};
