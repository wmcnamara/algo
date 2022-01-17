/*
    O(N) time complexity
    O(1) space complexity

    Solution to codewars "Bit Counting" problem. 

    6 kyu question

    https://www.codewars.com/kata/526571aae218b8ee490006f4
*/

unsigned int countBits(unsigned long long n)
{
    const int bitCount = sizeof(unsigned long long) * 8;

    int sum = 0;

    for (int i = 0; i < bitCount; i++)
    {
        if (n & (1ull << i))
            sum++;
    }

    return sum;
}