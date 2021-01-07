/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;

        queue<Node *> levels;
        levels.push(root);

        while (!levels.empty())
        {
            int level_size = levels.size();
            Node *n1 = NULL;
            for (int i = 0; i < level_size; ++i)
            {
                Node *n2 = levels.front();
                if (n1 == NULL)
                    n1 = n2;
                else
                    n1->next = n2;
                levels.pop();
                if (n2->left)
                    levels.push(n2->left);
                if (n2->right)
                    levels.push(n2->right);
                n1 = n2;
            }
            n1->next = NULL;
        }
        return root;
    }
};
// @lc code=end
