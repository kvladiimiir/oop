#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "lab_7\FindMaxEx\FindMaxEx\FindMaxEx.h"

struct Sportsman
{
	std::string name;
	double height;
	double weight;
};

bool IsHeavier(const Sportsman& first, const Sportsman& second)
{
	return (first.weight < second.weight);
}

bool IsHeigher(const Sportsman& first, const Sportsman& second)
{
	return (first.height < second.height);
}

bool IsThrow(const Sportsman& first, const Sportsman& second)
{
	throw std::logic_error("Is throw.");
}

Sportsman firstSportsman = { "Andrew Kino", 178.8, 71.5 };
Sportsman secondSportsman = { "Nikolay Sambrero", 198.8, 101.5 };
Sportsman thirdSportsman = { "Evgenyi Shlyapa", 190.0, 103.1 };

std::vector<Sportsman> emptySportmansVector = {};
std::vector<Sportsman> sportsmans = { firstSportsman, secondSportsman, thirdSportsman };

TEST_CASE("Test max height")
{
	Sportsman checkHeigherSportsman = secondSportsman;
	Sportsman heigherSportsman;
	FindMax(sportsmans, heigherSportsman, IsHeigher);
	REQUIRE(heigherSportsman.height == checkHeigherSportsman.height);
}

TEST_CASE("Test max weight")
{
	Sportsman checkHeavierSportsman = thirdSportsman;
	Sportsman heavierSportsman;
	FindMax(sportsmans, heavierSportsman, IsHeavier);
	REQUIRE(heavierSportsman.weight == checkHeavierSportsman.weight);
}

TEST_CASE("Test empty vector")
{
	Sportsman emptySportsman;
	CHECK(FindMax(emptySportmansVector, emptySportsman, IsHeavier) == false);
}

TEST_CASE("Test throw")
{
	Sportsman heavierSportsman;
	CHECK_THROWS_AS(FindMax(sportsmans, heavierSportsman, IsThrow), std::logic_error);
}