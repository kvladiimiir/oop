#include "pch.h"
#include "SieveEratosfen.h"

std::set<int> FillingSet(std::vector<bool>& metPrimeNumbers)
{
	std::set<int> primeNumbers;

	for (size_t i = 2; i < metPrimeNumbers.size(); i++)
	{
		if (metPrimeNumbers[i])
		{
			primeNumbers.insert(i);
		}
	}

	return primeNumbers;
}

std::set<int> GeneratePrimeNumbersSet(const int& upperBound)
{
	std::vector<bool> metPrimeNumbers(upperBound + 1, true);

	for (int i = 2; i * i <= upperBound; i++)
	{
		if (metPrimeNumbers[i])
		{
			for (int notPrimeNumber = i * i; notPrimeNumber <= upperBound; notPrimeNumber += i)
			{
				metPrimeNumbers[notPrimeNumber] = false;
			}
		}
	}

	return FillingSet(metPrimeNumbers);
}