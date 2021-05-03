#pragma once
#include <iostream>

//Weston McNamara 2021
//Returns true if the sorted array "arr" contains element n. Performs a binary search.
// O(log N)
/*
    int* arr : array to be searched
    int left : start index of array. Generally 0
    int right : end index of array. Generally the length of the array.
    int n : item to be searched for

    returns: a boolean indicating whether the value was found  
*/

inline bool ContainsBinarySearch(int* arr, int left, int right, int n) 
{
    if (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (arr[middle] == n)
            return true;

        if (arr[middle] < n)
            return ContainsBinarySearch(arr, middle + 1, right, n);

        return ContainsBinarySearch(arr, left, middle - 1, n);
    }

    return false;
}