//Problem 3 https://projecteuler.net/problem=3

#include <iostream>
#include <cmath>

// A function to find largest prime factor
unsigned long long maxPrimeFactors(unsigned long long n)
{
    unsigned long long maxPrime = -1;

    while (n % 2 == 0)
    {
        maxPrime = 2;
        n /= 2;
    }
    while (n % 3 == 0)
    {
        maxPrime = 3;
        n /= 3;
    }

    // now we have to iterate only for integers
    // who does not have prime factor 2 and 3
    for (unsigned long long i = 5; i <= sqrt(n); i += 6)
    {
        while (n % i == 0)
        {
            maxPrime = i;
            n = n / i;
        }
        while (n % (i + 2) == 0)
        {
            maxPrime = i + 2;
            n = n / (i + 2);
        }
    }

    if (n > 4)
        maxPrime = n;

    return maxPrime;
}

int main()
{
    unsigned long long const number = 600851475143ULL;

    std::cout << maxPrimeFactors(number);

}