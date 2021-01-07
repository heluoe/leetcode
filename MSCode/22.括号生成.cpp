/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
            return {};
        n_ = n;
        create_string(n, n, "");
        return res_;
    }

    void create_string(int l, int r, string s)
    {
        if (l == 0 && r == 0)
        {
            res_.push_back(s);
            return;
        }

        if (l > 0)
        {
            create_string(l - 1, r, s + "(");
        }
        if (r > l)
        {
            create_string(l, r - 1, s + ")");
        }
    }
    vector<string> res_;
    int n_;
};
// @lc code=end
