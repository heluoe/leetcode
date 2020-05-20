#include <vector>

using namespace std;
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
        vector<vector<int>> ret;
        if (!root)
            return {};
        do_process(root, 0, ret);
        return ret;
    }
    void do_process(TreeNode *Node, int level, vector<vector<int>> &ret)
    {
        if (!Node)
            return;
        if (ret.size() == level)
        {
            ret.push_back(vector<int>(1, Node->val));
        }
        else
        {
            ret[level].push_back(Node->val);
        }
        do_process(Node->left, level + 1, ret);
        do_process(Node->right, level + 1, ret);
    }
};
// @lc code=end
