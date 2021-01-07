/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    // TODO: Tarjan
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        preOrderSearch(root, p, vp1);
        preOrderSearch(root, q, vp2);
        if (vp1.size() > vp2.size())
            swap(vp2, vp2);
        set<TreeNode *> map_set;
        for (const auto c : vp1)
            map_set.insert(c);

        for (int i = 0; i < vp2.size(); ++i)
            if (map_set.find(vp2[i]) != map_set.end())
                return vp2[i];

        return root;
    }

    bool preOrderSearch(TreeNode *node, TreeNode *p, vector<TreeNode *> &vp)
    {
        if (node == NULL)
            return false;
        if (node == p)
        {
            vp.push_back(node);
            return true;
        }
        if (preOrderSearch(node->left, p, vp) || preOrderSearch(node->right, p, vp))
        {
            vp.push_back(node);
            return true;
        }
        return false;
    }
    vector<TreeNode *> vp1, vp2;
};
// @lc code=end
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4