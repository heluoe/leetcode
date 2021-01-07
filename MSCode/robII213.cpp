/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int len = nums.size();
        if (len < 2)
            return nums[0];
        if (len == 2)
            return max(nums[0], nums[1]);
        if (len == 3)
            return max(max(nums[0], nums[1]), nums[2]);

        vector<vector<int>> dp(2, vector<int>(len, 0));
        dp[0][0] = nums[0]; // rob first-> dp[0][len -2] no last
        dp[1][0] = 0;       // rob last -> dp[1][len -1]
        dp[0][1] = nums[0];
        dp[1][1] = nums[1];
        for (int i = 2; i < len; ++i)
        {
            dp[0][i] = max(dp[0][i - 1], nums[i] + dp[0][i - 2]);
            dp[1][i] = max(dp[1][i - 1], nums[i] + dp[1][i - 2]);
        }
        return max(dp[0][len - 2], dp[1][len - 1]);
    }
};
// @lc code=end
// [2,7,9,3,1]
// [4,1,2,7,5,3,1]