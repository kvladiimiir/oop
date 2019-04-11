// TV.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "CTVSet.h"
#include "TV.h"

using namespace std;

void PrintAllCommands()
{
	cout << "Turn On is 'TurnOn'\n" <<
		"Turn Off is 'TurnOff'\n" <<
		"Select channel is 'SelectChannel<number OR name channel>'\n" <<
		"Information is 'Info'\n" <<
		"Select previous channel is 'SelectPrevChannel'\n" <<
		"Set channel name is 'SetChannelName<number AND name channel>'\n" <<
		"Get channel name is 'GetChannelName<number channel>'\n" <<
		"Get number channel by name is 'GetChannelByName<name channel>'\n" <<
		"Delete channel name is 'DeleteChannelName<name channel>'\n" <<
		"Exit is 'Exit'\n\n";
}

bool IsNumber(const string &str)
{
	auto it = str.begin();
	while (it != str.end() && isdigit(*it))
	{
		++it;
	}

	return (!str.empty() && it == str.end());
}

string TrimExtraWhiteSpaces(string &input) {
	boost::algorithm::trim_all(input);
	return input;
}

bool CommandRecognition(const string& command, CTVSet& tv)
{
	if (command == "TurnOn")
	{
		tv.TurnOn();
	}
	else if (command == "TurnOff")
	{
		tv.TurnOff();
	}
	else if (command == "SelectChannel")
	{
		std::string numberStr;
		std::getline(cin, numberStr);
		std::istringstream iss(numberStr);

		if (!IsNumber(numberStr))
		{
			string nameChannelInput = TrimExtraWhiteSpaces(numberStr);
			tv.SelectChannel(nameChannelInput);
		}
		else
		{
			tv.SelectChannel(stoi(numberStr));
		}
	}
	else if (command == "Info")
	{
		tv.GetInfo();
	}
	else if (command == "Exit")
	{
		return false;
	}
	else if (command == "SelectPrevChannel")
	{
		tv.SelectPreviousChannel();
	}
	else if (command == "SetChannelName")
	{
		std::string nameNumChannel;
		std::getline(cin, nameNumChannel);
		std::istringstream iss(nameNumChannel);

		std::string numberChannel;

		iss >> numberChannel;

		if (!IsNumber(numberChannel))
		{
			throw std::logic_error("Not numeric argument\n");
		}

		iss.get();

		std::string nameChannel;

		std::getline(iss, nameChannel);

		string nameChannelInput = TrimExtraWhiteSpaces(nameChannel);

		tv.SetChannelName(stoi(numberChannel), nameChannelInput);
	}
	else if (command == "GetChannelName")
	{
		std::string numberStr;
		std::getline(cin, numberStr);
		std::istringstream iss(numberStr);

		if (!IsNumber(numberStr))
		{
			throw std::logic_error("Not numeric argument\n");
		}

		cout << tv.GetChannelName(stoi(numberStr)) << '\n';
	}
	else if (command == "GetChannelByName")
	{
		std::string numberStr;
		std::getline(cin, numberStr);
		std::istringstream iss(numberStr);

		std::string nameChannel;
		std::getline(iss, nameChannel);
		string nameChannelInput = TrimExtraWhiteSpaces(nameChannel);

		cout << tv.GetChannelByName(nameChannelInput) << '\n';
	}
	else if (command == "DeleteChannelName")
	{
		std::string numberStr;
		std::getline(cin, numberStr);
		std::istringstream iss(numberStr);

		std::string nameChannel;
		std::getline(iss, nameChannel);

		string nameChannelInput = TrimExtraWhiteSpaces(nameChannel);

		tv.DeleteChannelName(nameChannelInput);
	}
	else
	{
		cout << "Error command!\nCheck this command and try again!\n";
	}

	return true;
}

int main()
{
	CTVSet tv;
	string inputCommand = "";

	PrintAllCommands();

	bool nextPass = true;

	while (nextPass)
	{
		cout << "Your command: ";
		getline(cin, inputCommand);
		try
		{
			nextPass = CommandRecognition(inputCommand, tv);
		}
		catch (exception const & e)
		{
			cout << "Error: " << e.what();
		}
	}
}
