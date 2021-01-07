/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ret;
        if (matrix.empty())
            return ret;

        int row = matrix.size();
        int col = matrix[0].size();
        int m = 0;

        while (row > 0 && col > 0)
        {
            if (row == 1)
            {
                for (int idx = m; idx < m + col; ++idx)
                    ret.push_back(matrix[m][idx]);
                return ret;
            }
            if (col == 1)
            {
                for (int idx = m; idx < m + row; ++idx)
                    ret.push_back(matrix[idx][m]);
                return ret;
            }
            for (int idx = m; idx < m + col; ++idx)
            {
                ret.push_back(matrix[m][idx]);
            }
            for (int idx = m + 1; idx < m + row; ++idx)
            {
                ret.push_back(matrix[idx][m + col - 1]);
            }
            for (int idx = m + col - 2; idx >= m; --idx)
            {
                ret.push_back(matrix[m + row - 1][idx]);
            }

            for (int idx = m + row - 2; idx > m; --idx)
            {
                ret.push_back(matrix[idx][m]);
            }
            m++;
            row -= 2;
            col -= 2;
        }
        return ret;
    }
};
// @lc code=end
// [[7],[9],[6]]\n
// [[7,6,9]]\n
// [[2,3,4],[5,6,7],[8,9,10],[11,12,13],[14,15,16]]\n