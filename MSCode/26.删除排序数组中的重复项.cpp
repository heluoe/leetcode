/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty() || nums.size() < 2)
        {
            return nums.size();
        }
        int c1 = 0, c2 = 1;
        while (c2 < nums.size())
        {
            if (nums[c1] == nums[c2])
            {
                c2++;
            }
            else
            {
                if (c2 > c1 + 1)
                {
                    nums[c1 + 1] = nums[c2];
                }
                c1++;
                c2++;
            }
        }
        return c1 + 1;
    }
};
// @lc code=end
