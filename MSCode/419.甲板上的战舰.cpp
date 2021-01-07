/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        if (board.empty())
            return 0;
        row_ = board.size();
        col_ = board[0].size();
        int res = 0;
        for (int i = 0; i < row_; ++i)
        {
            for (int j = 0; j < col_; ++j)
            {
                if (board[i][j] == 'X')
                {
                    res++;
                    dfs(board, i, j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= row_ || j < 0 || j >= col_)
            return;
        if (board[i][j] == 'X')
        {
            board[i][j] = '.';
            dfs(board, i + 1, j);
            dfs(board, i - 1, j);
            dfs(board, i, j + 1);
            dfs(board, i, j - 1);
        }
    }
    int row_, col_;
};
// @lc code=end
