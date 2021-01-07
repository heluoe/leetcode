/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1 - nums[0];

        int num_sum = 0;
        for (int i = 0; i < n; ++i)
            num_sum += nums[i];

        int sum = n * (n + 1) / 2;

        return sum - num_sum;
    }
};
// @lc code=end
