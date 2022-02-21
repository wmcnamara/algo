/*
    Created by Weston McNamara wmcnamara.com

    Time complexity: O(N Log N)
    Space complexity: O(1)

    Easy leetcode problem. https://leetcode.com/problems/contains-duplicate-ii/
*/

#include <cmath>
#include <utility>
#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        if (nums.size() == 1) return false;
        if (nums.size() == 2) return nums[0] == nums[1] && 1 <= k;

        std::vector<std::pair<int, int>> newArrData(nums.size());

        for (int i = 0; i < newArrData.size(); i++)
        {
            newArrData[i] = { nums[i], i };
        }

        std::sort(newArrData.begin(), newArrData.end());

        for (int i = 1; i < newArrData.size() - 1; i++)
        {
            int current = newArrData[i].first;
            int left = newArrData[i - 1].first;
            int right = newArrData[i + 1].first;

            int currentI = newArrData[i].second;
            int leftI = newArrData[i - 1].second;
            int rightI = newArrData[i + 1].second;

            if (current == left)
            {
                if (abs(currentI - leftI) <= k)
                    return true;
            }

            if (current == right)
            {
                if (abs(currentI - rightI) <= k)
                    return true;
            }
        }


        return false;
    }
};