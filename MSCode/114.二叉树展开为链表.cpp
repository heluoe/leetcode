/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        preorder(root);
        TreeNode *node = root;
        for (int i = 1; i < vec_flat.size(); ++i)
        {
            node->right = vec_flat[i];
            node->left = NULL;
            node = node->right;
        }
        if (node->right)
        {
            node->left = NULL;
            node->right = NULL;
        }
        return;
    }
    void preorder(TreeNode *node)
    {
        if (node == NULL)
            return;
        vec_flat.push_back(node);
        preorder(node->left);
        preorder(node->right);
    }
    vector<TreeNode *> vec_flat;
};
// @lc code=end
