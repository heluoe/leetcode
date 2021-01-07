/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() < 2)
            return nums[0];
        int l = 0, r = nums.size() - 1;
        if (nums[l] < nums[r])
            return nums[l];
        while (l < r)
        {
            int p = (l + r) / 2;
            if (l <= p + 1 && p - 1 <= r && nums[p + 1] > nums[p] && nums[p - 1] > nums[p])
                return nums[p];
            else if (nums[l] > nums[r] && nums[p] > nums[l]) // right part broken
                l = p + 1;
            else if (nums[l] > nums[r] && nums[p] < nums[l]) // left part broken
                r = p - 1;
            else if (nums[l] < nums[r])
                return nums[l];
            else if (p == l)
                l++;
        }
        return nums[l];
    }
};
// @lc code=end
// [9,10,11,12,13,14,0]\n
// [2,1]\n
// [3,4,5,1,2]\n
// [3,1,2]\n
