/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution
{
public:
    string convertToTitle(int n)
    {
        string result;
        while (n > 0)
        {
            int m = n % 26;
            m = m == 0 ? 26 : m;
            result = string(1, 64 + m) + result;
            n = (n - m) / 26;
        }
        return result;
    }
};
// @lc code=end
// 1829842
