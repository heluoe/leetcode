#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() < 1 || grid[0].size() < 1)
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < row; ++i)
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        for (int i = 1; i < col; ++i)
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        for (int i = 1; i < row; ++i)
            for (int j = 1; j < col; ++j)
            {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }

        return dp[row - 1][col - 1];
    }

    int minPathSum2(vector<vector<int>> &grid)
    {
        if (grid.size() < 1 || grid[0].size() < 1)
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        auto min_rc = std::min(row, col);
        bool is_row_less = row < col;
        vector<int> dp(min_rc, 0);
        dp[0] = grid[0][0];
        if (is_row_less)
            for (int i = 1; i < min_rc; ++i)
                dp[i] = dp[i - 1] + grid[i][0];
        else
            for (int i = 1; i < min_rc; ++i)
                dp[i] = dp[i - 1] + grid[0][i];

        if (is_row_less)
        {
            for (int i = 1; i < col; ++i)
            {
                dp[0] = dp[0] + grid[0][i];
                for (int j = 1; j < row; ++j)
                {
                    dp[j] = std::min(dp[j - 1], dp[j]) + grid[j][i];
                }
            }
        }
        else
        {
            for (int i = 1; i < row; ++i)
            {
                dp[0] = dp[0] + grid[i][0];
                for (int j = 1; j < col; ++j)
                {
                    dp[j] = std::min(dp[j - 1], dp[j]) + grid[i][j];
                }
            }
        }
        return dp[min_rc - 1];
    }
};

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::uniform_int_distribution<int> uniform_k(0, 30);
    int N = static_cast<int>(std::round(uniform_k(v1)));
    Solution sol;
    vector<vector<int>> grid({{1, 2}, {1, 1}});
    std::cout << sol.minPathSum2(grid) << std::endl;
    return 0;
}