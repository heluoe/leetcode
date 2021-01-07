#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution
{
public:
    int binary_search_increase(vector<int> &nums, int target, int lo, int hi)
    {
        while (lo <= hi)
        {
            int idx = (lo + hi) / 2;
            if (target > nums[idx])
            {
                lo = idx + 1;
            }
            else if (target < nums[idx])
            {
                hi = idx - 1;
            }
            else
            {
                return idx;
            }
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        if (nums.size() < 2)
        {
            return target == nums[0] ? 0 : -1;
        }

        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi)
        {
            int idx = (lo + hi) / 2;
            if (nums[idx] == target)
            {
                return idx;
            }
            else if (nums[lo] == target)
            {
                return lo;
            }
            else if (nums[hi] == target)
            {
                return hi;
            }

            if (nums[lo] < nums[idx]) // right part broken
            {
                if (nums[lo] <= target && target <= nums[idx])
                    return binary_search_increase(nums, target, lo, idx);
                else
                {
                    lo = idx + 1;
                }
            }
            else //if (nums[idx] < nums[hi]) // left part broken
            {
                if (nums[idx] <= target && target <= nums[hi])
                    return binary_search_increase(nums, target, lo, hi);
                else
                {
                    hi = idx - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

/// [4,5,6,7,0,1,2]\n3
/// [4,5,6,7,0,1,2]\n5
/// [4,5,6,7,8,9,10,11,12,13,14,15,16,17,0,1,2,3]\n0
/// [5,1,3]\n3
/// [3,1]\n1
/// [5,1,2,3,4]\n1

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> nums = {5, 1, 2, 3, 4};
    std::cout << sol.search(nums, 1) << std::endl;

    return 0;
}