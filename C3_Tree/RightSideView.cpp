
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return {};
        process(root, 0);
        for (auto &que : queueBuf)
            ret.push_back(que.back());
        return ret;
    }
    void process(TreeNode *Node, int level)
    {
        if (!Node)
            return;
        if (queueBuf.size() == level)
        {
            queueBuf.push_back(vector<int>(1, Node->val));
        }
        else
            queueBuf[level].push_back(Node->val);
        process(Node->left, level + 1);
        process(Node->right, level + 1);
    }
    vector<vector<int>> queueBuf;
};
// @lc code=end
