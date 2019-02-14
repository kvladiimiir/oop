#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int NUM_ARGUMENT = 3;

bool IsValid(int numArg, string fileName)
{
	if (numArg != NUM_ARGUMENT)
	{
		cout << "Error arguments!\n";
		return false;
	}
	else if (fileName.empty())
	{
		cout << "File name is empty\n";
		return false;
	}
	else
	{
		return true;
	}
}

int main(int argc, char* argv[])
{
	string fileInputName = argv[1];

	if (!IsValid(argc, fileInputName))
	{
		return 1;
	}

	ifstream fileToSearch(fileInputName);

	if (!fileToSearch.is_open())
	{
		cout << "File is not open!\n";
		return 1;
	}

	string stringToFind;
	stringToFind = argv[2];

	if (stringToFind.empty())
	{
		cout << "Find string is empty\n";
		return 1;
	}

	int numOfCoincidences = 0;
	int lineNum = 0;

	while (!fileToSearch.eof())
	{
		string searchLine;

		getline(fileToSearch, searchLine);
		lineNum++;

		if (searchLine.find(stringToFind) != -1)
		{
			cout << lineNum << '\n';
			numOfCoincidences++;
		}
	}

	if (numOfCoincidences == 0)
	{
		cout << "Text not found!\n";
		return 1;
	}

	return 0;
}