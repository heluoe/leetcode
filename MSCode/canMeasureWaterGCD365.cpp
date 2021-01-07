/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution
{
public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (z > x + y)
            return false;
        if (z == 0 || ((x == 0 || y == 0) && x + y == z))
            return true;

        // z = a*x + b*y  a, b (-INT_MIN ~ INT_MAX)

        return z % gcd(x, y) == 0;
    }
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        if (a < b)
            return gcd(b, a);
        return gcd(b, a % b);
    }
};
// @lc code=end
