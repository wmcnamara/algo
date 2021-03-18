#pragma once
#include <iostream>

//Returns true if the sorted array "arr" contains element n. Performs a linear search.
// O(N)
/*
    int* arr : array to be searched
    int n : item to be searched for
    size_t size : length of array

    returns: a boolean indicating whether the value was found or not.
*/
inline bool ContainsLinear(int* arr, size_t size, int n)
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == n)
            return true;
    }

    return false;
}