/*
 * @lc app=leetcode.cn id=672 lang=cpp
 *
 * [672] 灯泡开关 Ⅱ
 */

// @lc code=start
class Solution
{
public:
    int flipLights(int n, int m)
    {
        int res = 8;
        if (m == 0)
            return 1;
        if (n == 0)
            return 3;

        if (m == 1)
        {
            if (n == 1)
                return 2;
            if (n == 2)
                return 3;

            return 4;
        }

        if (m == 2)
        {
            if (n == 1)
                return 2;
            if (n == 2)
                return 4;
            return 7;
        }

        if (n == 1)
            return 2;
        if (n == 2)
            return 4;
        return res;
    }
};
// @lc code=end

// 1\n2 2
