//Weston McNamara
//Problem 5 https://projecteuler.net/problem=5

#include <iostream>

bool DivisibleBy1To20(unsigned long n)
{
	for (int i = 2; i <= 20; i++)
	{
		if (n % i != 0)
			return false;
	}

	return true;
}

/*
	To meet the divisible by 1-20 requirement, a number has to end in a 0, because the only numbers that both 5 and 2 divide evenly into are 10.

	Because we know the number ends in zero, its a base of 10, and so we can count up in tens.
*/
int main()
{
	unsigned long i = 10;

	while (true)
	{
		if (DivisibleBy1To20(i))
		{
			std::cout << i;
			break;
		}

		i += 10;
	}
}