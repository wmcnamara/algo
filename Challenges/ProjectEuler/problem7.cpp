//Weston McNamara
//Problem 7 https://projecteuler.net/problem=7

#include <iostream>

bool isPrime(unsigned int n)
{
	if (n <= 1)
		return false;

	for (int i = 2; i < (n / 2) + 1; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main()
{
	unsigned int count = 1;
	unsigned int maxPrime = 0;
	unsigned int i = 0;

	for (int i = 1; count < 10001; i += 2)
	{
		if (i > maxPrime && isPrime(i))
		{
			maxPrime = i;
			count++;
		}
	}

	std::cout << maxPrime;
}