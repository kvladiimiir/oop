#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int NUM_ARGUMENT = 2;
const int NUM_SIZE = 8;

bool CheckNum(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] < '0') || (str[i] > '9'))
		{
			return false;
		}
	}
	return true;
}

int TransferNum(int numOnBit, vector<int> &numOfBinary)
{
	int i = 0;
	int resultNum = 0;
	while (numOnBit > 0)
	{
		numOfBinary[i] = numOnBit % 2;
		numOnBit = numOnBit / 2;
		i += 1;
	}

	for (unsigned int j = 0; j < numOfBinary.size(); j++)
	{
		resultNum = (resultNum * 2) + numOfBinary[j];
	}
	return resultNum;
}

int main(int argc, char* argv[])
{
	if (argc != NUM_ARGUMENT)
	{
		return 1;
	}

	vector<int> numBinary(NUM_SIZE, 0);

	string inputLine = argv[1];

	if ((inputLine == "") || (!CheckNum(inputLine)))
	{
		return 1;
	}

	int inputNum = stoi(inputLine);

	if ((inputNum < 0) || (inputNum > 255))
	{
		cout << "InputNum must be > 0 and < 256 \n";
		return 1;
	}

	int bitaryNum = TransferNum(inputNum, numBinary);
	cout << bitaryNum << '\n';

	return 0;
}