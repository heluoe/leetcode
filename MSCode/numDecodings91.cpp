/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.empty())
            return 0;
        int n = s.length();
        vector<int> dp(n + 1, 0);
        if (s[0] == '0')
            return 0;
        dp[0] = dp[1] = 1;

        for (int i = 1; i < n; ++i)
        {
            int code = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (s[i] > '0')
                dp[i + 1] = dp[i];
            if (9 < code && code < 27)
                dp[i + 1] = dp[i + 1] + dp[i - 1];
            else if (dp[i + 1] == 0)
            {
                return 0;
            }
        }
        return dp[n];
    }

    int numDecodingsUnKnown(string s)
    {
        if (s.empty())
            return 0;
        int n = s.length();
        vector<int> dp(n + 1, 1);
        dp[n - 1] = s[n - 1] == '0' ? 0 : 1;
        for (int i = n - 2; i >= 0; --i)
        {
            if (s[i] == '0')
            {
                dp[i] = 0;
            }
            else
            {
                int code = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (code <= 26)
                {
                    dp[i] = dp[i + 1] + dp[i + 2];
                }
                else
                {
                    dp[i] = dp[i + 1];
                }
            }
        }
        return dp[0];
    }
};
// @lc code=end

// "2345520123110" \n