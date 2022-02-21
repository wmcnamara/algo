/*
    Created by Weston McNamara wmcnamara.com

    Time complexity: O(N)
    Space complexity: O(N)

    Easy leetcode problem. https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/
*/

#include <algorithm>

bool equalsPlusMinus1(int n, int c)
{
    return n == c || n + 1 == c || n - 1 == c;
}

class Solution {
public:
    vector<int> findLonely(vector<int>& nums)
    {
        if (nums.size() == 1) return nums;

        if (nums.size() == 2 && !equalsPlusMinus1(nums[0], nums[1])) return nums;

        std::vector<int> lonely;
        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size() - 1; i++)
        {
            int current = nums[i];
            int left = nums[i - 1];
            int right = nums[i + 1];

            if (current == left || current == right)
                continue;

            if (current + 1 == left || current - 1 == left)
                continue;

            if (current + 1 == right || current - 1 == right)
                continue;

            lonely.push_back(current);
        }

        int first = nums[0];
        int second = nums[1];

        int last = nums[nums.size() - 1];
        int secondLast = nums[nums.size() - 2];

        if (first != second && first + 1 != second && first - 1 != second)
            lonely.push_back(first);

        if (last != secondLast && last + 1 != secondLast && last - 1 != secondLast)
            lonely.push_back(last);

        return lonely;
    }
};