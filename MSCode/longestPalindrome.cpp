#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string exp_s = "#";
        for (int i = 0; i < s.length(); ++i)
        {
            exp_s.push_back(s[i]);
            exp_s.push_back('#');
        }
        int max_len = 0, max_idx = 0, n = exp_s.length();
        for (int i = 0; i < exp_s.length(); ++i)
        {
            for (int j = 0; i - j >= 0 && i + j < n; ++j)
            {
                if (exp_s[i - j] == exp_s[i + j])
                {
                    if ((2 * j + 1) > max_len)
                    {
                        max_len = 2 * j + 1;
                        max_idx = i;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        max_len = max_len / 2;
        max_idx = max_idx / 2 - max_len / 2;
        return s.substr(max_idx, max_len);
    }

    string longestPalindromeCentral(string s)
    {
        /// Center export
        int max_len = 0, max_idx = 0, n = s.length();
        if (n == 1)
            return s;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; i - j >= 0 && i + j < n; ++j)
            {
                if (s[i - j] == s[i + j])
                {
                    if ((2 * j + 1) > max_len)
                    {
                        max_len = 2 * j + 1;
                        max_idx = i - j;
                    }
                }
                else
                {
                    break;
                }
            }
            for (int j = 0; i - j >= 0 && i + 1 + j < n; ++j)
            {
                if (s[i - j] == s[i + 1 + j])
                {
                    if (2 + 2 * j > max_len)
                    {
                        max_len = 2 + 2 * j;
                        max_idx = i - j;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return s.substr(max_idx, max_len);
    }

    string longestPalindromeDP(string s)
    {
        /// dp[s.len+2][s.len+2]
        /// dp[i][j] = true, i == j
        /// dp[i][j] = s[i] == s[j], i = j +1
        /// dp[i][j] = s[i] == s[j] && dp[i+1][j-1], i > j+1
        int max_len = 0, max_idx = 0, n = s.length();
        vector<vector<bool>> dp(n + 2, vector<bool>(n + 2, 0));
        for (int i = n; i >= 1; --i)
        {
            for (int j = i; j <= n; ++j)
            {
                if (i == j)
                {
                    dp[i][j] = true;
                }
                else if (i + 1 == j)
                {
                    dp[i][j] = s[i] == s[j];
                }
                else
                {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }
                if (j - i + 1 >= max_len)
                {
                    max_idx = i;
                    max_len = j - i + 1;
                }
            }
        }
        return s.substr(max_idx, max_len);
    }
};
// @lc code=end

int main(int argc, char **argv)
{
    /*
    "babad"
    ""
    "a"
    */
    Solution sol;
    std::cout << sol.longestPalindrome("babad") << std::endl;

    return 0;
}