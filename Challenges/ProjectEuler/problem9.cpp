//Weston McNamara
//Problem 9 https://projecteuler.net/problem=9

#include <iostream>
#include <cmath>

int main()
{
	for (long long a = 1; a < 1000; a++)
	{
		for (long long b = a + 1; b < 1000; b++)
		{
			long long aSqr = a * a;
			long long bSqr = b * b;
			long long c = round(sqrt(aSqr + bSqr));

			if (a + b + c == 1000 && aSqr + bSqr == c * c)
			{
				std::cout << a * b * c << '\n';
				break;
			}
		}
	}
}