/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    unordered_map<Node *, Node *> randomMap;
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;
        if (randomMap.find(head) != randomMap.end())
            return randomMap[head];

        Node *node = new Node(head->val);
        randomMap[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
    }
};
// @lc code=end
