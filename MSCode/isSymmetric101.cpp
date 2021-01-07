/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        queue<TreeNode *> level;
        level.push(root);
        while (!level.empty())
        {
            int level_size = level.size();
            vector<int> vals(level_size);
            for (int i = 0; i < level_size; ++i)
            {
                TreeNode *node = level.front();
                level.pop();
                vals[i] = node == NULL ? INT_MIN : node->val;
                if (node != NULL)
                {
                    level.push(node->left);
                    level.push(node->right);
                }
            }

            for (int l = 0, r = level_size - 1; l < r; ++l, --r)
            {
                if (vals[l] != vals[r])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
