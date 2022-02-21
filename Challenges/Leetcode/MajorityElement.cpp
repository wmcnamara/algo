/*
    Created by Weston McNamara wmcnamara.com

    Time complexity: O(N)
    Space complexity: O(N)

    Easy leetcode problem. https://leetcode.com/problems/majority-element
*/
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> occ;

        for (int i = 0; i < nums.size(); i++)
        {
            occ[nums[i]]++;
        }

        std::pair<int, int> max{};
        int count = nums.size() / 2;

        for (auto i : occ)
        {
            if (i.second > max.second)
                max = i;
        }

        return max.first;
    }
};