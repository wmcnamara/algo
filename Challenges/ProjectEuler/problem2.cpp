//Problem 2 https://projecteuler.net/problem=2

#include <iostream>

int main()
{
    long long prev = 1;
    long long cur = 1;
    long long sum = 0;
    long long result = 0;

    while (result < 4000000)
    {
        long long calc = prev + cur;

        if (calc % 2 == 0)
            sum += calc;

        prev = cur;
        cur = calc;

        result = calc;
    }

    std::cout << sum << '\n';
}