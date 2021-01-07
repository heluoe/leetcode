/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;

        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode *node, long min, long max)
    {
        if (node == NULL)
            return true;
        if (min >= node->val || node->val >= max)
            return false;
        return isValidBST(node->left, min, node->val) && isValidBST(node->right, node->val, max);
    }
};
// @lc code=end
// [2,1,3]\n