/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution
{
public:
    int hammingWeightO0(uint32_t n)
    {
        return bitset<32>(n).count();
    }
    int hammingWeight(uint32_t n)
    {
        uint32_t f = 1;
        int result = 0;
        while (n > 0)
        {
            if ((n & f) > 0)
                result++;
            n = (n >> 1);
            // cout << bitset<32>(n) << endl;
        }
        return result;
    }
    int hammingWeightOn(uint32_t n)
    {
        uint32_t f = 0;
        int restul = 0;
        for (int i = 0; i < 32; ++i)
        {
            f = pow(2, i);
            if ((f & n) > 0)
                restul++;
        }
        return restul;
    }
};
// @lc code=end
