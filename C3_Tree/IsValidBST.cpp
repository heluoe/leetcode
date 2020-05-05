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
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode *root)
    {
        TreeNode *last = NULL;
        return isValidBST(root, last);
    }
    bool isValidBST(TreeNode *root, TreeNode *&last)
    { //last指针引用记录上一次访问的节点，注意要用引用类型。
        if (!root)
            return true;
        if (!isValidBST(root->left, last) || (last && last->val >= root->val)) //若左子树非BST，或者前驱节点不小于当前节点，返回false。
            return false;
        last = root;                          //每次访问过一个节点后，将last指向当前节点。
        return isValidBST(root->right, last); //若右子树也是BST，则返回true。
    }
};
// @lc code=end

/*
[5,1,4,null,null,3,6]
*/