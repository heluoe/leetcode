#include <iostream>
#include <stack>
#include <random>
#include <algorithm>
#include <cmath>

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
    ////////////////////////
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return ret;
        if (root)
            ret.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return ret;
    }

    vector<int> preorderTraversalUnRecur(TreeNode *root)
    {
        if (!root)
            return ret;
        std::stack<TreeNode *> bufStack;
        bufStack.push(root);
        while (!bufStack.empty())
        {
            TreeNode *head = bufStack.top();
            bufStack.pop();
            ret.push_back(head->val);
            if (head->right)
                bufStack.push(head->right);
            if (head->left)
                bufStack.push(head->left);
        }

        return ret;
    }
    ////////////////////////

    ////////////////////////
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return ret;

        inorderTraversal(root->left);
        ret.push_back(root->val);
        inorderTraversal(root->right);

        return ret;
    }

    vector<int> inorderTraversalUnRecur(TreeNode *root)
    {
        if (!root)
            return ret;

        std::stack<TreeNode *> bufStack;
        TreeNode *cur = root;
        while (cur || !bufStack.empty())
        {
            if (cur)
            {
                bufStack.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = bufStack.top();
                ret.push_back(cur->val);
                bufStack.pop();
                cur = cur->right;
            }
        }

        return ret;
    }
    ////////////////////////

    ////////////////////////
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return ret;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ret.push_back(root->val);

        return ret;
    }

    vector<int> postorderTraversalUnRecur(TreeNode *root)
    {
        if (!root)
            return ret;

        std::stack<TreeNode *> bufStack;
        TreeNode *cur = root;
        bufStack.push(cur);
        while (!bufStack.empty())
        {
            cur = bufStack.top();
            if (cur->left && root != cur->left && root != cur->right)
            {
                bufStack.push(cur->left);
            }
            else if (cur->right && root != cur->right)
            {
                bufStack.push(cur->right);
            }
            else
            {
                ret.push_back(cur->val);
                bufStack.pop();
                root = cur;
            }
        }

        return ret;
    }
    ////////////////////////
    std::vector<int> ret;
};

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    std::uniform_int_distribution<int> uniform_x(0, 15);

    return 0;
}