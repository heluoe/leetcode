/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        if (nums.empty())
            return;
        int c1 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[c1] = nums[i];
                c1++;
            }
        }
        for (int i = c1; i < nums.size(); ++i)
        {
            nums[i] = 0;
        }
    }
    void moveZeroesSlow(vector<int> &nums)
    {
        if (nums.empty())
            return;

        int l = 0, r = nums.size() - 1;
        for (int i = r; i >= 0; --i)
        {
            if (nums[i] == 0)
            {
                for (int j = i; j < r; ++j)
                {
                    swap(nums[j], nums[j + 1]);
                }
                r--;
            }
        }
    }
};
// @lc code=end
