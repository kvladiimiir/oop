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

bool ReadInputData(Terr& terr, string& fileInputName)
{
	string line;
	int numstr = 0;

	ifstream fileInput(fileInputName);

	if (!fileInput.is_open())
	{
		return 1;
	}

	while (getline(fileInput, line))
	{
		if (numstr >= 100)
			break;
		vector<char> str;
		terr.mapTerr.push_back(str);
		int numsym = 0;
		for (char symb : line)
		{
			if (numsym >= 100)
				break;

			terr.mapTerr[terr.mapTerr.size() - 1].push_back(symb);

			if (symb == 'O')
			{
				CoordPoint newStartPoint;
				newStartPoint.y = terr.mapTerr.size() - 1;
				newStartPoint.x = terr.mapTerr[newStartPoint.y].size() - 1;
				cout << newStartPoint.y << ' ' << newStartPoint.x << '\n';
				terr.startPoint.push_back(newStartPoint);
			}
			numsym++;
		}
		numstr++;
	}
	return true;
}

void FillTerr(Terr& terr, size_t col, size_t row)
{
	terr.mapTerr.resize(100);
	const auto rowsSize = terr.mapTerr.size();
	if (rowsSize - 1 < row || rowsSize == 0 || row >= 100 || row < 0)
		return;
	const auto colsSize = terr.mapTerr[row].size();
	if (colsSize == 0 || col < 0 || col >= 100 || colsSize - 1 < col)
		return;
	if (terr.mapTerr[row][col] == ' ')
	{
		terr.mapTerr[row][col] = '_';
		FillTerr(terr, col + 1, row);
		FillTerr(terr, col - 1, row);
		FillTerr(terr, col, row - 1);
		FillTerr(terr, col, row + 1);
	}
}

bool OutputData(Terr& terr, string fileOutputName)
{
	ofstream fileOutput(fileOutputName);

	if (!fileOutput.is_open())
	{
		return false;
	}

	for (vector<char> line : terr.mapTerr)
	{
		for (char symb : line)
		{
			fileOutput << symb;
		}
		fileOutput << '\n';
	}

	return true;
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

	Terr mapTerrInput;

	if (!ReadInputData(mapTerrInput, fileInputName))
	{
		return 1;
	}

	for (size_t i = 0; i < mapTerrInput.startPoint.size(); i++)
	{
		auto coordX = mapTerrInput.startPoint[i].x;
		auto coordY = mapTerrInput.startPoint[i].y;
		mapTerrInput.mapTerr[coordY][coordX] = ' ';
		FillTerr(mapTerrInput, coordX, coordY);
		mapTerrInput.mapTerr[coordY][coordX] = 'O';
	}

	if (!OutputData(mapTerrInput, fileOutputName))
	{
		return 1;
	}

	return 0;
}