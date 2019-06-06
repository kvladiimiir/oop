#pragma once

#include <iostream>
#include <vector>

template < typename T, typename Less >
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& Less)
{
	if (arr.empty())
	{
		return false;
	}

	T maxElement = arr[0];

	for (size_t i = 1; i < arr.size(); i++)
	{
		if (Less(maxElement, arr[i]))
		{
			maxElement = arr[i];
		}
	}

	maxValue = maxElement;

	return true;
}