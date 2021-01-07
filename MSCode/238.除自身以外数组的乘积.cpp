/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        //On
        int n = nums.size();
        vector<int> res(n, 1);

        ///         2        3       4       5           6
        ///L:res    1        2 *1    3*2*1   4*3*2*1  5*4*3*2*1
        ///R:k      3*4*5*6  4*5*6   5*6*1   6*1         1
        ///Final  k*res[i]

        res[0] = 1;
        for (int i = 1; i < n; ++i) // left part multi
        {
            res[i] = nums[i - 1] * res[i - 1];
        }

        int k = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            k *= nums[i + 1];
            res[i] = k * res[i];
        }
        return res;
    }
};
// @lc code=end
