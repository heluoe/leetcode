#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        if (text1.length() < 1 || text2.length() < 1)
            return 0;
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), 0));

        for (size_t i = 0; i < text2.length(); ++i)
        {
            if (text1.at(0) == text2.at(i) || (i > 0 && dp[0][i - 1] == 1))
            {
                dp[0][i] = 1;
            }
        }
        for (size_t i = 0; i < text1.length(); ++i)
        {
            if (text2.at(0) == text1.at(i) || (i > 0 && dp[i - 1][0] == 1))
            {
                dp[i][0] = 1;
            }
        }

        for (size_t i = 1; i < text1.length(); ++i)
        {
            for (size_t j = 1; j < text2.length(); ++j)
            {
                auto cur = std::max(dp[i - 1][j], dp[i][j - 1]);
                if (text2.at(j) == text1.at(i))
                    cur = std::max(cur, dp[i - 1][j - 1] + 1);
                dp[i][j] = cur;
            }
        }
        return dp[text1.length() - 1][text2.length() - 1];
    }
};
// @lc code=end

int main(int argc, char **argv)
{
    // [[46,89],[50,53],[52,68],[72,45],[77,81]] 3
    // [[5,4],[6,4],[6,7],[2,3]] 3
    // [[4,5],[4,6],[6,7],[2,3],[1,1]]  4
    //std::vector<vector<int>> vec({{5, 4}, {6, 4}, {6, 7}, {2, 3}});
    // std::vector<vector<int>> vec({{5, 4}, {6, 4}, {6, 7}, {2, 3}});
    // Solution sol;
    // std::cout << sol.maxEnvelopes(vec) << std::endl;
    return 0;
}
