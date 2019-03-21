#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <set>
#include "lab_2\WorkVector\GeneratePrimeNumbers\SieveEratosfen.h"

TEST_CASE("Check size setPrimeNumbers")
{
	REQUIRE(GeneratePrimeNumbersSet(0).size() == 0);
	REQUIRE(GeneratePrimeNumbersSet(2).size() == 1);
	REQUIRE(GeneratePrimeNumbersSet(10).size() == 4);
};

TEST_CASE("Check setPrimeNumbers")
{
	REQUIRE(GeneratePrimeNumbersSet(0) == std::set<int> {});
	REQUIRE(GeneratePrimeNumbersSet(2) == std::set<int> { 2 });
	REQUIRE(GeneratePrimeNumbersSet(10) == std::set<int> { 2, 3, 5, 7 });
};

TEST_CASE("Check setPrimeNumbers at 100000000")
{
	REQUIRE(GeneratePrimeNumbersSet(100000000).size() == 5761455);
};