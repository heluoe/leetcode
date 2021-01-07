
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.empty() || inorder.size() != postorder.size())
            return NULL;
        int m = postorder.size();
        TreeNode *root = new TreeNode(postorder[m - 1]);
        int next_il, next_pl;
        for (int i = 0; i < m; ++i)
        {
            if (postorder[m - 1] == inorder[i])
            {
                root->left = create_child(inorder, postorder, 0, i - 1, 0, i - 1);
                root->right = create_child(inorder, postorder, i + 1, m - 1, i, m - 2);
            }
        }

        return root;
    }
    TreeNode *create_child(vector<int> &inorder, vector<int> &postorder, int il, int ir, int pl, int pr)
    {
        if (pl > pr || il > ir)
            return NULL;
        TreeNode *node = new TreeNode(postorder[pr]);
        for (int i = il; i <= ir; ++i)
        {
            if (postorder[pr] == inorder[i])
            {
                node->left = create_child(inorder, postorder, il, i - 1, pl, pl + i - il - 1);
                node->right = create_child(inorder, postorder, i + 1, ir, pl + i - il, pr - 1);
            }
        }
        return node;
    }
};
// @lc code=end

int main(int argc, char **argv)
{
    vector<int> nums1 = {9, 3, 15, 20, 7};
    vector<int> nums2 = {9, 15, 7, 20, 3};
    Solution sol;
    sol.buildTree(nums1, nums2);

    return 0;
}