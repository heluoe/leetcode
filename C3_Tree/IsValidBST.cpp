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
        if (!root)
            return true;
        // return isValidBST(root, -1);
        // TreeNode *last = NULL;
        // return isValidBST(root, last);

        return isValidBST(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    }
    bool isValidBST(TreeNode *root, long minVal, long maxVal)
    {
        if (!root)
            return true;
        if (root->val <= minVal || root->val >= maxVal)
            return false;
        return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
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
    bool isValidBST(TreeNode *root, int last)
    { //last指针引用记录上一次访问的节点，注意要用引用类型。
        if (!root)
            return true;

        if (!isValidBST(root->left, last) || (last > 0 && root->left && last <= root->left->val)) //若左子树非BST，或者前驱节点不小于当前节点，返回false。
            return false;

        //每次访问过一个节点后，将last指向当前节点。
        //若右子树也是BST，则返回true。
        last = root->val;
        return isValidBST(root->right, last);
    }
};
// @lc code=end

/*
[5,1,4,null,null,3,6]
[10,5,15,null,null,6,20]
*/