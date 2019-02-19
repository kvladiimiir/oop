#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int NUM_ARGUMENT = 3;

int FindTextInFile(ifstream& fileInput, string& findString)
{
	int numOfCoincidences = 0;
	int lineNum = 0;
	string searchLine;

	while (getline(fileInput, searchLine))
	{
		lineNum++;

		if (searchLine.find(findString) != string::npos)
		{
			cout << lineNum << '\n';
			numOfCoincidences++;
		}
	}

	return numOfCoincidences;
}

int main(int argc, char* argv[])
{
	if (argc != NUM_ARGUMENT)
	{
		cout << "Error arguments!\n";
		return 1;
	}

	string fileInputName = argv[1];
	string stringToFind = argv[2];

	if (fileInputName.empty())
	{
		cout << "File name is empty\n";
		return 1;
	}
	else if (stringToFind.empty())
	{
		cout << "Find string is empty\n";
		return 1;
	}

	ifstream fileToSearch(fileInputName);

	if (!fileToSearch.is_open())
	{
		cout << "File is not open!\n";
		return 1;
	}

	int numCoincidences = FindTextInFile(fileToSearch, stringToFind);

	if (numCoincidences == 0)
	{
		cout << "Text not found!\n";
		return 1;
	}

	return 0;
}