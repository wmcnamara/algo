/*
    Created by Weston McNamara wmcnamara.com

    Time complexity: O(N)
    Space complexity: O(N)

    Medium leetcode problem. https://leetcode.com/problems/majority-element-ii/
*/

#include <unordered_map>
#include <cmath>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int threshold = ceil(nums.size() / 3);

        std::unordered_map<int, int> occurance;
        std::vector<int> values;

        for (int i = 0; i < nums.size(); i++)
        {
            ++occurance[nums[i]];
        }

        for (auto [value, occ] : occurance)
        {
            if (occ > threshold)
                values.push_back(value);
        }

        return values;
    }
};