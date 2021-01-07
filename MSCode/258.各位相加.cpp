/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        if (num < 9)
            return num;
        int x = num % 9;
        return x == 0 ? 9 : x;
    }
};
// @lc code=end
