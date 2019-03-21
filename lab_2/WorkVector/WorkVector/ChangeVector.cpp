#include "pch.h"
#include "ChangeVector.h"

void SortVector(std::vector<double>& vectorNum)
{
	std::sort(vectorNum.begin(), vectorNum.end());
}

std::vector<double> WorkWithVector(std::vector<double>& vectorNum)
{
	double minElement = *std::min_element(vectorNum.begin(), vectorNum.end());

	std::vector<double> resultVector = vectorNum;

	for (size_t i = 0; i < vectorNum.size(); i++)
	{
		resultVector[i] = resultVector[i] * minElement;
	}

	SortVector(resultVector);

	return resultVector;
}