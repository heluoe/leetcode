/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> results;
        if (root == NULL)
            return results;

        queue<TreeNode *> levels;
        levels.push(root);
        bool dir_front = true;
        while (!levels.empty())
        {
            int level_size = levels.size();
            vector<int> vals(level_size);

            for (int i = 0; i < level_size; ++i)
            {
                TreeNode *node = levels.front();
                levels.pop();
                vals[i] = node->val;
                if (node->left)
                    levels.push(node->left);
                if (node->right)
                    levels.push(node->right);
            }
            // if (!level.empty())
            //     cout << level.front()->val << ", " << dir_front << endl;
            if (!dir_front)
            {
                vector<int> inv_vals(level_size);
                for (int i = 0; i < level_size; ++i)
                {
                    inv_vals[level_size - 1 - i] = vals[i];
                }
                results.push_back(inv_vals);
            }
            else
            {
                results.push_back(vals);
            }

            dir_front = !dir_front;
        }
        return results;
    }
};
// @lc code=end

// [1,2,3,4,null,null,5]\n
// [3,9,20,null,null,15,7]\n