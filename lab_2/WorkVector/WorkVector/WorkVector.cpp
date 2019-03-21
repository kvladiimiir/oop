#include "pch.h"
#include "ChangeVector.h"

bool FillVector(std::vector<double>& vectorNum)
{
	double number;

	std::string numberStr;
	std::getline(std::cin, numberStr);
	std::istringstream iss(numberStr);

	try
	{
		number = std::stoi(numberStr);
	}
	catch (const std::invalid_argument&)
	{
		return false;
	}

	while (iss >> number)
	{
		vectorNum.push_back(number);
	}

	return true;
}

void PrintVector(std::vector<double>& vectorNum)
{
	for (size_t i = 0; i < vectorNum.size(); i++)
	{
		std::cout << vectorNum[i] << ", ";
	}
	std::cout << '\n';
}

int main(int argc, char* argv[])
{
	if (argc != NUM_ARGUMENT)
	{
		return 1;
	}

	std::vector<double> vectorOFNum;

	if (!FillVector(vectorOFNum))
	{
		return 1;
	}

	WorkWithVector(vectorOFNum);

	SortVector(vectorOFNum);

	PrintVector(vectorOFNum);

	return 0;
}