/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        if (nums.empty())
            return;
        vector<int> color_count(3, 0);
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            color_count[nums[i]]++;
        }
        int base = 0;
        for (int j = 0; j < 3; ++j)
        {
            for (int i = 0; i < color_count[j]; ++i)
            {
                nums[base + i] = j;
            }
            base += color_count[j];
        }
    }
};
// @lc code=end
