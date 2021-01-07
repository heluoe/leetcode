/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;

        vector<int> dp(n + 1, 1);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = i;
            for (int j = i / 2; j > 1; --j)
            {
                if (i % j == 0)
                {
                    dp[i] = dp[i / j] + dp[j];
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
