/*
    O(N) time complexity
    O(1) space complexity

    Solution to the codewars "gap in primes" problem. 

    4 kyu question

    https://www.codewars.com/kata/561e9c843a2ef5a40c0000a4
*/

#include <iostream>
#include <math.h>

bool IsPrime(long long n)
{
    if (n == 1 || n == 0)
        return false;

    long long max = (int)sqrt(n);

    for (long long i = 2; i <= max + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

class GapInPrimes
{
public:
    static std::pair<long long, long long> gap(int g, long long m, long long n)
    {
        long long prevPrime = 0;

        for (long long i = m; i <= n; i++)
        {
            if (IsPrime(i))
            {
                if (i - prevPrime == g && prevPrime != 0)
                    return { prevPrime, i };
                else
                    prevPrime = i;
            }
        }

        return std::pair{ 0, 0 };
    }
};