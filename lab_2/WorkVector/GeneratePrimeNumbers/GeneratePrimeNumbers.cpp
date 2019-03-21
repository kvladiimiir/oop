#include "pch.h"
#include "SieveEratosfen.h"

void PrintPrimeNumbers(std::set<int>& setPrimeNumbers)
{
	for (std::set<int>::iterator i = setPrimeNumbers.begin(); i != setPrimeNumbers.end(); i++)
	{
		std::cout << *i << ' ';
	}
}

int main()
{
	int inputNum;

	std::cin >> inputNum;

	if ((inputNum > MAX_NUM) || (inputNum < 0))
	{
		return 1;
	}

	if (inputNum < 2)
	{
		return 1;
	}

	std::set<int> setNumbers = GeneratePrimeNumbersSet(inputNum);

	PrintPrimeNumbers(setNumbers);

	return 0;
}