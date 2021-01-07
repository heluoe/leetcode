/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> dp(n);
        int max_len = 0;
        for (int num : nums)
        {
            int l = 0, r = max_len;
            while (l < r)
            {
                int c = (l + r) / 2;
                if (dp[c] < num)
                    l++;
                else
                    r = c;
            }
            dp[l] = num;
            if (l == max_len)
                max_len++;
        }
        return max_len;
    }
    int lengthOfLISOnn(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        dp[0] = 1;
        int max_len = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_len = max(dp[i], max_len);
        }
        return max_len;
    }
};
// @lc code=end
