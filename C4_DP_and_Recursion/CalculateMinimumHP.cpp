#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        if (dungeon.empty())
            return 0;
        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), 0));
        int row = dungeon.size() - 1, col = dungeon[0].size() - 1;

        dp[row][col] = dungeon[row][col] > 0 ? 1 : -dungeon[row][col] + 1;

        for (int i = col - 1; i >= 0; --i)
        {
            dp[row][i] = std::max(dp[row][i + 1] - dungeon[row][i], 1);
        }

        for (int i = row - 1; i >= 0; --i)
        {
            dp[i][col] = std::max(dp[i + 1][col] - dungeon[i][col], 1);
            for (int j = col - 1; j >= 0; --j)
            {
                auto right = std::max(dp[i][j + 1] - dungeon[i][j], 1);
                auto down = std::max(dp[i + 1][j] - dungeon[i][j], 1);
                dp[i][j] = std::min(right, down);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

/*
[[0,0]]
*/

int main(int argc, char **argv)
{

    std::vector<vector<int>> vec({{0, 0}});
    Solution sol;
    std::cout << sol.calculateMinimumHP(vec) << std::endl;
    return 0;
}