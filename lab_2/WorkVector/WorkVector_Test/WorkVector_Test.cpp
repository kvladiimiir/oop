#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lab_2\WorkVector\WorkVector\ChangeVector.h"

TEST_CASE("Chech WorkWithVector()")
{
	{
		std::vector<double> numbers = { 1, 2, 3, 6, 4 };
		std::vector<double> result = WorkWithVector(numbers);
		std::vector<double> compare = { 1, 2, 3, 4, 6 };
		REQUIRE(result == compare);
	}

	{
		std::vector<double> numbers = { 1, -2, 3, 6, 4 };
		std::vector<double> result = WorkWithVector(numbers);
		std::vector<double> compare = { -12, -8, -6, -2, 4 };
		REQUIRE(result == compare);
	}
}