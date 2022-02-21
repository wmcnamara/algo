/*
    Created by Weston McNamara wmcnamara.com

    Time complexity: O(N)
    Space complexity: O(1)

    Easy leetcode problem. https://leetcode.com/problems/duplicate-zeros/
*/
#include <iostream>

class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] == 0)
            {
                for (int j = arr.size() - 2; j > i; j--)
                {
                    arr[j + 1] = arr[j];
                }

                arr[i + 1] = 0;
                i++;
            }
        }
    }
};