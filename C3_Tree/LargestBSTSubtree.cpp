#include <iostream>
#include <stack>
#include <random>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
 * @lc app=leetcode.cn id=333 lang=cpp
 *
 * [333] 最大 BST 子树
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
    int largestBSTSubtree(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxCount = countBSTSubTree(root);
        maxCount = std::max(maxCount, countBSTSubTree(root->left));
        maxCount = std::max(maxCount, countBSTSubTree(root->right));
        return maxCount;
    }
    int countBSTSubTree(TreeNode *node)
    {
        if (node && isBSTree(node, MIN_VAL, MAX_VAL))
            return countBSTSubTree(node->left) + countBSTSubTree(node->right) + 1;
        return 0;
    }
    bool isBSTree(TreeNode *node, long min, long max)
    {
        if (!node)
            return true;
        if (node->val < min || node->val > max)
            return false;
        return isBSTree(node->left, min, node->val) && isBSTree(node->right, node->val, max);
    }
    long MIN_VAL = std::numeric_limits<long>::min();
    long MAX_VAL = std::numeric_limits<long>::max();
};
// @lc code=end