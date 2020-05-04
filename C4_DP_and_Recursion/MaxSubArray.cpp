#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int ret = dp[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            ret = std::max(ret, dp[i]);
        }
        return ret;
    }
};
// @lc code=end
