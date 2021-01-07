/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode *root)
    {
        if (root == NULL)
            return -1;

        queue<TreeNode *> q_nodes;
        q_nodes.push(root);
        int res = -1;
        while (!q_nodes.empty())
        {
            int n = q_nodes.size();
            res = q_nodes.front()->val;
            for (int i = 0; i < n; ++i)
            {
                TreeNode *node = q_nodes.front();
                q_nodes.pop();
                if (node->left != NULL)
                    q_nodes.push(node->left);
                if (node->right != NULL)
                    q_nodes.push(node->right);
            }
        }

        return res;
    }
};
// @lc code=end
