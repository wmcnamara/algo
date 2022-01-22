//Weston McNamara
//Problem 6 https://projecteuler.net/problem=6

#include <iostream>

int main()
{
	unsigned long long sumOfSquares = 0;
	unsigned long long squareOfSums = 0;

	for (unsigned long long i = 1; i <= 100; i++)
	{
		sumOfSquares += i * i;
		squareOfSums += i;
	}

	squareOfSums = squareOfSums * squareOfSums;

	unsigned long long difference = squareOfSums - sumOfSquares;

	std::cout << difference;
}