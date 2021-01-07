/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        if (nums.empty())
            return -1;
        if (nums.size() < 2)
            return nums[0];

        int n = nums.size();
        build_tree(nums, n);
        swap(nums[0], nums[n - 1]);
        for (int i = 2; i <= k; ++i)
        {
            heapify(nums, n - i + 1, 0);
            swap(nums[0], nums[n - i]);
        }
        return nums[n - k];
    }

    void build_tree(vector<int> &nums, int n)
    {
        int last_node = n - 1;
        int parent_node = (last_node - 1) / 2;
        for (int i = parent_node; i >= 0; --i)
        {
            heapify(nums, n, i);
        }
    }

    void heapify(vector<int> &nums, int n, int i)
    {
        if (i >= n)
            return;
        int c1 = i * 2 + 1; //child node idx
        int c2 = i * 2 + 2;
        int max = i;
        if (c1 < n && nums[max] < nums[c1])
            max = c1;
        if (c2 < n && nums[max] < nums[c2])
            max = c2;
        if (max != i)
        {
            swap(nums[max], nums[i]);
            heapify(nums, n, max);
        }
        return;
    }
};
// @lc code=end
