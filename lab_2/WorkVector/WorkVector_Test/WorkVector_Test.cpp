#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lab_2\WorkVector\WorkVector\ChangeVector.h"

TEST_CASE("Check WorkWithVector()")
{
	{
		std::vector<double> numbers = { 1, 2, 3, 6, 4 };
		WorkWithVector(numbers);
		SortVector(numbers);
		std::vector<double> result = { 1, 2, 3, 4, 6 };
		REQUIRE(numbers == result);
	}
}

TEST_CASE("Negative WorkWithVector()")
{
	{
		std::vector<double> numbers = { 1, -2, 3, 6, 4 };
		WorkWithVector(numbers);
		SortVector(numbers);
		std::vector<double> compare = { -12, -8, -6, -2, 4 };
		REQUIRE(numbers == compare);
	}
}

TEST_CASE("Empty WorkWithVector()")
{
	{
		std::vector<double> numbers = {};
		WorkWithVector(numbers);
		SortVector(numbers);
		std::vector<double> compare = {};
		REQUIRE(numbers == compare);
	}
}