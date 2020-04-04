#include <iostream>
#include <utility>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

/*
// Definition for a Node.
*/
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == NULL)
            return root;
        auto rootPair = doProcess(root);
        rootPair.first->left = rootPair.second;
        rootPair.second->right = rootPair.first;
        return rootPair.first;
    }

    std::pair<Node *, Node *> doProcess(Node *head)
    {
        Node *start = NULL, *end = NULL;
        if (head == NULL)
            return std::make_pair(start, end);
        auto leftList = doProcess(head->left);
        auto rightList = doProcess(head->right);
        if (leftList.second != NULL)
            leftList.second->right = head;
        head->left = leftList.second;
        head->right = rightList.first;
        if (rightList.first != NULL)
            rightList.first->left = head;
        return std::make_pair((leftList.first != NULL ? leftList.first : head), (rightList.second != NULL ? rightList.second : head));
    }
};

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    std::uniform_int_distribution<int> uniform_k(6, 18);

    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    Solution sol;
    auto head = sol.treeToDoublyList(root);
    Node *cur = head;
    std::cout << "Forward right: " << std::endl;
    while (cur->right != head)
    {
        std::cout << cur->val << " ";
        cur = cur->right;
    }
    std::cout << std::endl;
    cur = head;
    std::cout << "Forward left: " << std::endl;
    while (cur->left != head)
    {
        std::cout << cur->val << " ";
        cur = cur->left;
    }
    std::cout << std::endl;
    return 0;
}