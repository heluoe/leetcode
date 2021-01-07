/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return root;
        betweenBST(root, p, q);
        return result_;
    }
    void betweenBST(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (min(p->val, q->val) <= node->val && node->val <= max(p->val, q->val))
        {
            result_ = node;
            return;
        }
        else if (node->val > q->val && node->val > p->val)
            betweenBST(node->left, p, q);
        else
            betweenBST(node->right, p, q);
    }
    TreeNode *result_;

    TreeNode *lowestCommonAncestorBad(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return root;
        dfs(root, p, sp1);
        dfs(root, q, sp2);

        if (sp1.size() > sp2.size())
            swap(sp1, sp2);
        unordered_map<int, TreeNode *> tree_map;
        for (const auto c : sp1)
            tree_map[c->val] = c;

        for (int i = sp2.size() - 1; i >= 0; --i)
            if (tree_map.find(sp2[i]->val) != tree_map.end())
                return tree_map[sp2[i]->val];

        return q;
    }
    void dfs(TreeNode *node, TreeNode *p, vector<TreeNode *> &sp)
    {
        if (p == node)
        {
            sp.push_back(p);
            return;
        }
        sp.push_back(node);
        if (p->val > node->val)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
        dfs(node, p, sp);
    }
    vector<TreeNode *> sp1, sp2;
};
// @lc code=end
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n4
