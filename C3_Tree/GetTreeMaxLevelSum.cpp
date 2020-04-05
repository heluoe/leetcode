#include <iostream>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>

// #112. Path Sum
// #437. Path Sum III
/**
 * Definition for a binary tree node.
 */
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    int pathSum(TreeNode *root, int sum)
    {
        unordered_map<int, int> sumMap;
        sumMap[0] = 1;
        return preorderTraversal(root, sum, 0, sumMap);
    }
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr && sum - root->val == 0)
        {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
    //////
    int preorderTraversal(TreeNode *root, int K, int curSum, unordered_map<int, int> &sumMap)
    {
        int ret = 0;
        if (!root)
            return 0;
        curSum += root->val;
        ret = sumMap.find(curSum - K) != sumMap.end() ? sumMap[curSum - K] : 0;
        sumMap[curSum] = sumMap.find(curSum) != sumMap.end() ? sumMap[curSum] + 1 : 1;

        ret += preorderTraversal(root->left, K, curSum, sumMap);
        ret += preorderTraversal(root->right, K, curSum, sumMap);
        sumMap[curSum] -= 1;
        return ret;
    }
};