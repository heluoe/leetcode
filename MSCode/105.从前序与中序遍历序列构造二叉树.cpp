/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
            return NULL;
        int n = preorder.size();
        TreeNode *root = new TreeNode(preorder[0]);
        int idx = 0;
        for (int i = 0; i < n; ++i)
        {
            if (inorder[i] == root->val)
            {
                ++idx;
                root->left = create_child(preorder, inorder, 0, i - 1, idx);
                root->right = create_child(preorder, inorder, i + 1, n - 1, idx);
                break;
            }
        }
        return root;
    }
    TreeNode *create_child(vector<int> &preorder, vector<int> &inorder, int l, int r, int &idx)
    {
        if (l < 0 || l > r)
            return NULL;
        TreeNode *node = NULL;
        for (int i = l; i <= r; ++i)
        {
            if (inorder[i] == preorder[idx])
            {
                ++idx;
                node = new TreeNode(inorder[i]);
                node->left = create_child(preorder, inorder, l, i - 1, idx);
                node->right = create_child(preorder, inorder, i + 1, r, idx);
                break;
            }
        }
        return node;
    }
};
// @lc code=end
