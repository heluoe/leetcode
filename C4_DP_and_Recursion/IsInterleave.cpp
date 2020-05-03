#include <iostream>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;
        if ((s2.empty() && s1 == s3) || (s1.empty() && s2 == s3))
            return true;
        else if ((s1.empty() && s2 != s3) || (s2.empty() && s2 != s3))
            return false;

        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= s2.length(); ++i)
        {
            dp[0][i] = (s3[i - 1] == s2[i - 1]) & dp[0][i - 1];
        }
        for (int i = 1; i <= s1.length(); ++i)
        {
            dp[i][0] = (s3[i - 1] == s1[i - 1]) & dp[i - 1][0];
        }

        for (int i = 1; i <= s1.length(); ++i)
        {
            for (int j = 1; j <= s2.length(); ++j)
            {
                dp[i][j] = dp[i - 1][j] & (s1[i - 1] == s3[j - 1 + i]);
                dp[i][j] = dp[i][j] | (dp[i][j - 1] & (s2[j - 1] == s3[i - 1 + j]));
                dp[i][j] = dp[i][j] | (dp[i - 1][j - 1] & ((s2[j - 1] == s3[i - 1 + j - 1] && s1[i - 1] == s3[i - 1 + j]) || (s1[i - 1] == s3[i - 1 + j - 1] && s2[j - 1] == s3[i - 1 + j])));
            }
        }
        return dp[s1.length()][s2.length()];
    }
};
// @lc code=end

/*
"aabcc"\n"dbbca"\n"aadbbbaccc"


*/