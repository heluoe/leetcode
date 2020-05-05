#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution
{
public:
    // bool PredictTheWinner(vector<int> &nums)
    // {
    //     if (nums.empty())
    //         return false;
    //     return f(nums, 0, nums.size() - 1) >= s(nums, 0, nums.size() - 1);
    // }
    bool PredictTheWinner(vector<int> &nums)
    {
        if (nums.empty())
            return false;

        vector<vector<int>> f(nums.size(), vector<int>(nums.size(), 0)), s(nums.size(), vector<int>(nums.size(), 0));
        for (int j = 0; j < nums.size(); ++j)
        {
            f[j][j] = nums[j];
            for (int i = j - 1; j >= 0; --i)
            {
                f[i][j] = std::max(nums[i] + s[i + 1][j], nums[j] + s[i][j - 1]);
                s[i][j] = std::min(f[i + 1][j], f[i][j - 1]);
            }
        }
        return f[0][nums.size() - 1] >= s[0][nums.size() - 1];
    }
    int f(vector<int> &nums, int i, int j)
    {
        if (i == j)
            return nums[i];
        return std::max(nums[i] + s(nums, i + 1, j), nums[j] + s(nums, i, j - 1));
    }
    int s(vector<int> &nums, int i, int j)
    {
        if (i == j)
            return 0;
        return std::min(f(nums, i + 1, j), f(nums, i, j - 1));
    }
};
// @lc code=end
/*
[1, 5, 233, 7]
*/