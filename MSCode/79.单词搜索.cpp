/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty())
            return false;
        row_ = board.size();
        col_ = board[0].size();
        bool result = false;
        for (int i = 0; i < row_; ++i)
        {
            for (int j = 0; j < col_; ++j)
            {
                result = matirx_search(board, word, 0, i, j);
                if (result)
                    return result;
            }
        }
        return result;
    }
    bool matirx_search(vector<vector<char>> &board, string &word, int t, int rx, int cx)
    {
        if (t < word.length() && rx < row_ && rx >= 0 && cx < col_ && cx >= 0)
        {
            if (board[rx][cx] == word[t] && record.find(rx * col_ + cx) == record.end())
            {
                if (t == word.length() - 1)
                    return true;
                record.insert(rx * col_ + cx);

                if (matirx_search(board, word, t + 1, rx, cx + 1))
                    return true;
                if (matirx_search(board, word, t + 1, rx, cx - 1))
                    return true;
                if (matirx_search(board, word, t + 1, rx + 1, cx))
                    return true;
                if (matirx_search(board, word, t + 1, rx - 1, cx))
                    return true;

                record.erase(rx * col_ + cx);
            }
            return false;
        }
        else
        {
            return false;
        }
    }
    int row_, col_;
    set<int> record;
};
// @lc code=end
