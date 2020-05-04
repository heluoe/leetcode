#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91]  Decode Ways
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.empty() || s[0] == '0')
            return 0;

        vector<int> dp(s.length() + 1, 1);
        dp[s.length() - 1] = s[s.length() - 1] == '0' ? 0 : 1;
        for (int i = s.length() - 2; i >= 0; --i)
        {
            if (s[i] == '0')
                dp[i] = 0;
            else
            {
                if ((s[i] - '0') * 10 + s[i + 1] - '0' < 27)
                    dp[i] = dp[i + 1] + dp[i + 2];
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

/*
"110"
"1111"
"10"
"01"
"12120"
"17"

*/
