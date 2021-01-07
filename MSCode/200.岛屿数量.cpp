/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        if (grid.empty())
            return count;

        row_ = grid.size();
        col_ = grid[0].size();

        for (int i = 0; i < row_; ++i)
        {
            for (int j = 0; j < col_; ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (i < 0 || i >= row_ || j < 0 || j >= col_)
            return;

        if (grid[i][j] == '1')
        {
            grid[i][j] = '0';
            dfs(i + 1, j, grid);
            dfs(i - 1, j, grid);
            dfs(i, j + 1, grid);
            dfs(i, j - 1, grid);
        }
    }

    // int numIslands(vector<vector<char>> &grid)
    // {
    //     int count = 0;
    //     if (grid.empty())
    //         return count;

    //     row_ = grid.size();
    //     col_ = grid[0].size();

    //     vector<vector<int>> map(row_, vector<int>(col_, 0));
    //     for (int i = 0; i < row_; ++i)
    //     {
    //         for (int j = 0; j < col_; ++j)
    //         {
    //             dfs(i, j, grid, map, 0);
    //         }
    //     }
    //     return count_;
    // }
    // int dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &map, int flag)
    // {
    //     if (i < 0 || i >= row_ || j < 0 || j >= col_)
    //         return 0;

    //     if (grid[i][j] == '1' && map[i][j] == 0)
    //     {
    //         flag++;
    //         if (flag == 1)
    //             count_++;
    //         map[i][j] = flag;
    //         dfs(i + 1, j, grid, map, flag);
    //         dfs(i - 1, j, grid, map, flag);
    //         dfs(i, j + 1, grid, map, flag);
    //         dfs(i, j - 1, grid, map, flag);

    //         return flag;
    //     }
    //     if (map[i][j] != 0)
    //         return map[i][j];
    //     else //if (grid[i][j] == '0')
    //         return 0;
    // }
    // int count_;
    int row_;
    int col_;
};
// @lc code=end

/*
[
["1","1","0","0","0"],
["1","1","0","0","0"],
["0","0","1","0","0"],
["0","0","0","1","1"]
]
*/