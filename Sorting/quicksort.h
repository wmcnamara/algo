// Weston McNamara 2021
//Sorts an array with the quick sort algorithm
/*
    arr: Array to be sorted
    l: left index of array. Generally the start.
    r: end of the array.

    Divide and conquer algorithm

    Time complexity:

    Best and Average: O(n log n)
    Worst case: O(n^2)
*/

#include <iostream>

//Swaps items in array at index x and y
void swap(int* arr, int x, int y)
{
    int tmp = arr[x];

    arr[x] = arr[y];
    arr[y] = tmp;
}

//Paritions the objects using the last element as the pivot.
int partition(int* arr, int l, int r)
{
    int piv = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < piv)
        {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, r);
    return i + 1;
}

//Sorts an array recursively
void qsort(int* arr, int l, int r)
{
    if (l < r)
    {
        int j = partition(arr, l, r);
        qsort(arr, l, j - 1);
        qsort(arr, j + 1, r); //recurse until sorted
    }
}

int main()
{
    int arrayToSort[8] = { 0, 5, 1, 4, 0, 6, 7, 10 };

    std::cout << "Unsorted Array: " << "\n";
    for (int i = 0; i < 8; i++)
    {
        std::cout << arrayToSort[i] << "\n";
    }

    qsort(arrayToSort, 0, 7);

    std::cout << "\n\nSorted Array With Quicksort: " << "\n";
    for (int i = 0; i < 8; i++)
    {
        std::cout << arrayToSort[i] << "\n";
    }

    return 0;
}