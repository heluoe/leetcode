/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return result;

        stack<TreeNode *> TreeBuffer;
        TreeNode *cur = root;
        while (cur || !TreeBuffer.empty())
        {
            if (cur)
            {
                TreeBuffer.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = TreeBuffer.top();
                result.push_back(cur->val);
                TreeBuffer.pop();
                cur = cur->right;
            }
        }
        return result;
    }

    vector<int> inorderTraversalRecur(TreeNode *root)
    {
        if (root == NULL)
            return result;
        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);
        return result;
    }

    vector<int> result;
};
// @lc code=end
