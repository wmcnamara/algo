#pragma once
#include <iostream>

//Created by Weston McNamara in 2021
//Returns true if the sorted array "arr" contains element n. 
//Binary search.

/*
    arr: Array to be sorted
    len: Length of the array.

    Time complexity:
    O(n^2)
*/

bool StringEqual(const char* str1, const char* str2)
{
    char* current = str1;
    int i = 0;

    while (*current != '\0')
    {
        if (str1[i] != str2[i])
            return false;

        i++;
        current++;
    }

    return true;
}

int StringCompare(const char* str1, const char* str2)
{
    if (str1 == str2)
        return 0;

    if (StringEqual(str1, str2))
        return 0;

    return 1;
}

int main()
{
    int arr[10] = { 2, 5, 1, 0, 2 };
    BubbleSort(arr, 5);

    for (int i = 0; i < 5; i++)
        std::cout << arr[i];
}
