#define CATCH_CONFIG_MAIN
#include "lab_3\TV\CTVSet.h"
#include "catch.hpp"

TEST_CASE("Check function TurnOn")
{
	CTVSet tv;
	tv.TurnOn();
	REQUIRE_THROWS(tv.TurnOn());
}

TEST_CASE("Check function TurnOff")
{
	CTVSet tv;
	REQUIRE_THROWS(tv.TurnOff());
}

TEST_CASE("Check function SelectChannel")
{
	CTVSet tv;
	REQUIRE_THROWS(tv.SelectChannel(12));
	tv.TurnOn();
	REQUIRE_THROWS(tv.SelectChannel(123));
	std::string nameChannel = "Sport";
	REQUIRE_THROWS(tv.SelectChannel(nameChannel));
}

TEST_CASE("Check function SelectPreviousChannel")
{
	CTVSet tv;
	REQUIRE_THROWS(tv.SelectPreviousChannel());
}

TEST_CASE("Check function SetChannelName")
{
	CTVSet tv;
	int numberChannel = 12;
	std::string nameChannel = "Russia1";
	REQUIRE_THROWS(tv.SetChannelName(numberChannel, nameChannel));

	tv.TurnOn();
	tv.SetChannelName(numberChannel, nameChannel);
	nameChannel = "Sport";
	REQUIRE_THROWS(tv.SetChannelName(numberChannel, nameChannel));

	nameChannel = "";
	REQUIRE_THROWS(tv.SetChannelName(numberChannel, nameChannel));

	numberChannel = 120;
	nameChannel = "Russia";
	REQUIRE_THROWS(tv.SetChannelName(numberChannel, nameChannel));
}

TEST_CASE("Check function GetChannelName and GetChannelByName")
{
	CTVSet tv;
	tv.TurnOn();
	int numberChannel = 12;
	std::string nameChannel = "Russia1";
	tv.SetChannelName(numberChannel, nameChannel);

	std::string name = "Russia1";
	REQUIRE(tv.GetChannelName(numberChannel) == name);

	REQUIRE(tv.GetChannelByName(name) == numberChannel);

	name = "";
	REQUIRE_THROWS(tv.GetChannelByName(name));

	name = "as";
	REQUIRE_THROWS(tv.GetChannelByName(name));

	numberChannel = 19;
	REQUIRE_THROWS(tv.GetChannelName(numberChannel));
}

TEST_CASE("Check function DeleteChannelName")
{
	CTVSet tv;
	std::string nameChannel = "Russia1";

	REQUIRE_THROWS(tv.DeleteChannelName(nameChannel));

	tv.TurnOn();
	int numberChannel = 12;
	tv.SetChannelName(numberChannel, nameChannel);

	tv.DeleteChannelName(nameChannel);

	nameChannel = "Asd";
	REQUIRE_THROWS(tv.DeleteChannelName(nameChannel));
}

TEST_CASE("Check function GetInfo")
{
	CTVSet tv;
	REQUIRE_THROWS(tv.GetInfo());
}

TEST_CASE("TV")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(19);
	std::string nameChannel = "Russia1";
	tv.SetChannelName(12, nameChannel);
	nameChannel = "Sport";
	tv.SetChannelName(3, nameChannel);

	REQUIRE(tv.GetChannelName(3) == "Sport");
	REQUIRE(tv.GetChannelByName(nameChannel) == 3);

	tv.DeleteChannelName(nameChannel);
	REQUIRE_THROWS(tv.GetChannelName(3));
	REQUIRE_THROWS(tv.GetChannelByName(nameChannel));

	tv.TurnOff();
	REQUIRE_THROWS(tv.GetChannelName(12));
}