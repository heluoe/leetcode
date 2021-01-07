/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> results;
        if (root == NULL)
            return results;

        queue<TreeNode *> levels;
        levels.push(root);
        while (!levels.empty())
        {

            int level_size = levels.size();
            vector<int> vals(level_size);
            for (int i = 0; i < level_size; ++i)
            {
                TreeNode *node = levels.front();
                levels.pop();
                vals[i] = node->val;
                if (node->left != NULL)
                    levels.push(node->left);
                if (node->right != NULL)
                    levels.push(node->right);
            }
            results.push_back(vals);
        }
        return results;
    }
};
// @lc code=end
