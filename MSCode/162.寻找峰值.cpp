/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution
{
public:
    int findPeakElementOlogN(vector<int> &nums)
    {
        // O(logN)
        if (nums.empty())
            return INT_MIN;
        else if (nums.size() < 2)
            return 0;
        else if (nums.size() == 2)
            return nums[0] > nums[1] ? 0 : 1;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int p = l + (r - l) / 2; // ???

            if (nums[p] > nums[p + 1]) // follow the peak on left part
                r = p;
            else // follow the peak on right part
                l = p + 1;
        }

        return l;
    }

    int findPeakElement(vector<int> &nums)
    {
        if (nums.empty())
            return INT_MIN;
        else if (nums.size() < 2)
            return 0;
        else if (nums.size() == 2)
            return nums[0] > nums[1] ? 0 : 1;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int p = (l + r) / 2;
            if (p - 1 < 0 && nums[p] > nums[p + 1])
                return p;
            else if (p + 1 >= nums.size() && nums[p] > nums[p - 1])
                return p;
            else if (nums[p - 1] < nums[p] && nums[p] > nums[p + 1])
                return p;

            if (nums[p] < nums[p + 1])
                l++;
            else
                r--;
        }

        return l;
    }
};
// @lc code=end

// [3,2,1]\n
// [3,4,3,2,1]\n