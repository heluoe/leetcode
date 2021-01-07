/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        maxSum = root->val;
        postorder(root);

        return maxSum;
    }
    int postorder(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        int leftsum = max(postorder(node->left), 0);
        int rightsum = max(postorder(node->right), 0);
        maxSum = max(node->val + leftsum + rightsum, maxSum);
        return node->val + max(0, max(leftsum, rightsum));
    }
    int maxSum;
};
// @lc code=end

// [1,2]\n
// [1,-2,-3,1,3,-2,null,-1]\n
// [5,4,8,11,null,13,4,7,2,null,null,null,1]\n