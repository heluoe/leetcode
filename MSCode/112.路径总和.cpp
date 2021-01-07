/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL)
            return root->val == sum;
        return (preorder(root->left, sum, root->val) || preorder(root->right, sum, root->val));
    }
    bool preorder(TreeNode *node, int sum, int presum)
    {
        if (node == NULL)
            return false;

        int cursum = presum + node->val;
        if (sum == cursum && node->left == NULL && node->right == NULL)
            return true;

        if (preorder(node->left, sum, cursum))
            return true;
        if (preorder(node->right, sum, cursum))
            return true;
        return false;
    }
};
// @lc code=end
// [1,2]\n 1\n
// [1]\n1\n
// [1,2,null,3,null,4,null,5]\n6\n
//