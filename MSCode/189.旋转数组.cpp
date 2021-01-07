/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution
{
public:
    void reverse(vector<int> &nums, int l, int h)
    {
        while (l < h)
        {
            swap(nums[l++], nums[h--]);
        }
    }
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        int step = k % len;
        reverse(nums, 0, len - step - 1);
        reverse(nums, len - step, len - 1);
        reverse(nums, 0, len - 1);
    }
    void rotateOn(vector<int> &nums, int k)
    {
        int len = nums.size();
        int step = k % len;
        vector<int> buf;
        for (int i = len - step; i < len; ++i)
            buf.push_back(nums[i]);
        for (int i = 0; i < len - step; ++i)
            buf.push_back(nums[i]);
        swap(nums, buf);
    }
};
// @lc code=end
