/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        // double p = 0.0;
        int c = 0;
        for (int i = 0; i < n; ++i)
        {
            c += is_prime(i);
            // int t3 = pow(3, i);
            // double p = (int)pow(1.30637788386308, t3);
            // cout << p << endl;
        }
        return c;
    }
    int is_prime(int x)
    {
        if (x < 2)
            return 0;
        for (int i = 2; i * i <= x; ++i)
            if (x % i == 0)
                return 0;

        return 1;
    }
};
// @lc code=end
