#include "pch.h"
#include "SieveEratosfen.h"

std::set<int> GeneratePrimeNumbersSet(const int& upperBound)
{
	std::set<int> primeNumbers;

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

	for (int i = 2; i <= upperBound; i++)
	{
		if (metPrimeNumbers[i])
		{
			primeNumbers.insert(i);
		}
	}

	return primeNumbers;
}