#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int NUM_ARGUMENT = 3;

int main(int argc, char* argv[])
{
	if (argc != NUM_ARGUMENT)
	{
		cout << "Error arguments!\n";
		return 1;
	}

	string fileInputName = argv[1];

	if (fileInputName.empty())
	{
		cout << "File name is empty\n";
		return 1;
	}

	ifstream fileToSearch(fileInputName);
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