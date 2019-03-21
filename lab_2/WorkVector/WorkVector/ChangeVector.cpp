#include "pch.h"
#include "ChangeVector.h"

void SortVector(std::vector<double>& vectorNum)
{
	std::sort(vectorNum.begin(), vectorNum.end());
}

void WorkWithVector(std::vector<double>& resultVector)
{
	if (resultVector.size() != 0)
	{
		double minElement = *std::min_element(resultVector.begin(), resultVector.end());

		for (size_t i = 0; i < resultVector.size(); i++)
		{
			resultVector[i] = resultVector[i] * minElement;
		}
	}
}