/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        if (height.size() < 2)
            return -1;

        int l = 0, r = height.size() - 1;
        int res = INT_MIN;
        while (l < r)
        {
            res = max((r - l) * min(height[l], height[r]), res);
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return res;
    }
};
// @lc code=end
