/*
    O(N) time complexity
    O(N) space complexity

    Solution to the codewars "sum of intervals" problem. 

    4 kyu question

    https://www.codewars.com/kata/52b7ed099cdc285c300001cd
*/

#include <vector>
#include <utility>
#include <set>

int sum_intervals(std::vector<std::pair<int, int>> intervals) 
{
    std::set<int> data;

    for (const auto& p : intervals)
    {
        for (int i = p.first; i < p.second; i++)
        {
            data.insert(i);
        }
    }

    return std::size(data);
}