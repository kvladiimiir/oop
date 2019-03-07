#include "pch.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const int MAX_SIZE_TER = 100;
const int NUM_ARGUMENT = 3;

using namespace std;

struct CoordPoint
{
	int x;
	int y;
};

struct Terr
{
	vector<vector <char>> mapTerr;
	vector<CoordPoint> startPoint;
};

void ReadInputData(Terr& terr, ifstream& inputFile)
{
	string line;
	int numstr = 0;

	while (terr.mapTerr.size() < MAX_SIZE_TER)
	{
		getline(inputFile, line)

			vector<char> str;
		terr.mapTerr.push_back(str);

		for (char symb : line)
		{
			terr.mapTerr[terr.mapTerr.size() - 1].push_back(symb);

			if (symb == 'O')
			{
				CoordPoint newStartPoint;
				newStartPoint.y = terr.mapTerr.size() - 1;
				newStartPoint.x = terr.mapTerr[newStartPoint.y].size() - 1;
				cout << newStartPoint.y << ' ' << newStartPoint.x << '\n';
				terr.startPoint.push_back(newStartPoint);
			}
		}
	}
}

void FillTerr(Terr& terr, size_t col, size_t row)
{
	if (terr.mapTerr[col][row] == ' ')
	{
		terr.mapTerr[col][row] = '_';
		FillTerr(terr, col + 1, row);
		FillTerr(terr, col - 1, row);
		FillTerr(terr, col, row - 1);
		FillTerr(terr, col, row + 1);
	}
}

int main(int argc, char *argv[])
{
	if (argc != NUM_ARGUMENT)
	{
		return 1;
	}

	string fileInputName = argv[1];
	string fileOutputName = argv[2];

	if (fileInputName.empty() || fileOutputName.empty())
	{
		return 1;
	}

	ifstream fileInput("input2.txt");
	ofstream fileOutput(fileOutputName);

	if (!fileInput.is_open())
	{
		return 1;
	}

	if (!fileOutput.is_open())
	{
		return 1;
	}

	Terr mapTerrInput;



	ReadInputData(mapTerrInput, fileInput);

	cout << mapTerrInput.startPoint.size() << '\n';

	for (size_t i = 0; i < mapTerrInput.startPoint.size(); i++)
	{
		size_t coordX = mapTerrInput.startPoint[i].x;
		size_t coordY = mapTerrInput.startPoint[i].y;
		cout << coordX << ' ' << coordY << '\n';
		FillTerr(mapTerrInput, coordX, coordY);
	}

	for (vector<char> line : mapTerrInput.mapTerr)
	{
		for (char symb : line)
		{
			cout << symb;
		}
		cout << '\n';
	}

	return 0;
}