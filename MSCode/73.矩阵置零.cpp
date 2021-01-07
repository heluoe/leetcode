/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return;
        int row = matrix.size();
        int col = matrix[0].size();
        bool row_flag = false, col_flag = false;
        for (int i = 0; i < col; ++i)
        {
            if (matrix[0][i] == 0)
            {
                row_flag = true;
                break;
            }
        }
        for (int i = 0; i < row; ++i)
        {
            if (matrix[i][0] == 0)
            {
                col_flag = true;
                break;
            }
        }
        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < row; ++i)
            for (int j = 1; j < col; ++j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }

        if (col_flag)
        {
            for (int i = 0; i < row; ++i)
                matrix[i][0] = 0;
        }
        if (row_flag)
        {
            for (int i = 0; i < col; ++i)
                matrix[0][i] = 0;
        }

        return;
    }
    void setZeroesOmn(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return;
        int row = matrix.size();
        int col = matrix[0].size();
        set<int> set_row, set_col;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    set_row.insert(i);
                    set_col.insert(j);
                }
            }
        }

        for (const auto r : set_row)
        {
            for (int i = 0; i < col; ++i)
                matrix[r][i] = 0;
        }
        for (const auto c : set_col)
        {
            for (int i = 0; i < row; ++i)
                matrix[i][c] = 0;
        }
        return;
    }
};
// @lc code=end
