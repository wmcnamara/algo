#pragma once
#include <iostream>

//Created by Weston McNamara in 2020
//Returns true if the sorted array "arr" contains element n. 
//Binary search.

/*
    arr: Array to be sorted
    len: Length of the array.

    Time complexity:
    O(n^2)
*/

int* BubbleSort(int* arr, size_t len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (arr[j] > arr[i])
            {            
                //Swap
                int tmp = arr[i];

                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    return arr;
}

int main()
{
    int arr[10] = { 2, 5, 1, 0, 2 };
    BubbleSort(arr, 5);

    for (int i = 0; i < 5; i++)
        std::cout << arr[i];
}
