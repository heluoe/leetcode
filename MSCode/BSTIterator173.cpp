/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        node_ = root;
        while (node_ != NULL)
        {
            bufStack.push(node_);
            node_ = node_->left;
        }
    }

    /** @return the next smallest number */
    int next()
    {
        int ret = 0;
        if (node_ == NULL)
        {
            node_ = bufStack.top();
            ret = node_->val;
            bufStack.pop();
            node_ = node_->right;
        }
        while (node_ != NULL)
        {
            bufStack.push(node_);
            node_ = node_->left;
        }

        return ret;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !bufStack.empty();
    }
    TreeNode *node_ = NULL;
    stack<TreeNode *> bufStack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

/*
 if (node_->right != NULL)
            {
                node = node_->right;
                while (node != NULL)
                {
                    node_ = node;
                    node = node->left;
                }
            }
            else if (parent_node->right != node_)
            {
                node_ = parent_node;
            }
            else
            {
                node_ = parent_node;
                parent_node = NULL;
                node = root;
                while (node_ == node)
                {
                    if (node_->val < node->val)
                    {
                        parent_node = node;
                        node = node->left;
                    }
                    else
                    {
                        parent_node = node;
                        node = node->right;
                    }
                }
            }
            */