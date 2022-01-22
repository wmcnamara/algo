//Problem 4 https://projecteuler.net/problem=4

#include <iostream>
#include <string>

bool isPalindrome(unsigned long long n)
{
    std::string str = std::to_string(n);

    size_t i = 0;
    size_t j = str.length() - 1;

    while (i <= j)
    {
        if (str[i] != str[j])
            return false;

        i++;
        j--;
    }

    return true;
}

int main()
{
    unsigned long long max = 0;

    for (unsigned long long i = 100; i <= 999; i++)
    {
        for (unsigned long long j = 100; j <= 999; j++)
        {
            unsigned long long n = j * i;

            if (isPalindrome(n) && n > max)
            {
                max = n;
            }
        }
    }

    std::cout << max;
}