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
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return root->left == NULL || root->right == NULL ? left + right + 1 : min(left, right) + 1;
    }
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