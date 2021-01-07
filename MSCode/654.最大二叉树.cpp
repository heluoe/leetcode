/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.empty())
            return NULL;

        return createMaxTree(nums, 0, nums.size() - 1);
    }

    TreeNode *createMaxTree(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return NULL;
        if (l == r)
        {
            return new TreeNode(nums[l]);
        }
        int max_num = INT_MIN, max_idx = l;
        for (int i = l; i <= r; ++i)
        {
            if (max_num < nums[i])
            {
                max_num = nums[i];
                max_idx = i;
            }
        }

        TreeNode *node = new TreeNode(nums[max_idx]);
        node->left = createMaxTree(nums, l, max_idx - 1);
        node->right = createMaxTree(nums, max_idx + 1, r);
        return node;
    }
};
// @lc code=end
