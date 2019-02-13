#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	string fileInputName = argv[1];
	ifstream fileToSearch(fileInputName);

	if (!fileToSearch.is_open())
	{
		cout << "File is not open!\n";
	}
	else
	{
		string stringToFind;
		stringToFind = argv[2];

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
		}
	}
	return 0;
}