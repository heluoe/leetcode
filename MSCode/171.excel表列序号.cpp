/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution
{
public:
    int titleToNumber(string s)
    {
        int result = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            int m = s[i] - 64;
            result = 26 * result + m;
        }
        return result;
    }
};
// @lc code=end
