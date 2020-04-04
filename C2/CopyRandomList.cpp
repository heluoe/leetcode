
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    std::unordered_map<Node *, Node *> hmap;
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        if (hmap.find(head) != hmap.end())
            return hmap[head];
        Node *node = new Node(head->val);
        hmap[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);

        return node;
    }

    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;
        std::unordered_map<Node *, Node *> noteMap;
        Node *cur = head;
        while (cur != NULL)
        {
            if (noteMap.find(cur) == noteMap.end())
                noteMap[cur] = new Node(cur->val);

            if (cur->next == NULL)
                noteMap[cur]->next = NULL;
            else if (noteMap.find(cur->next) != noteMap.end())
                noteMap[cur]->next = noteMap[cur->next];
            else
            {
                noteMap[cur->next] = new Node(cur->next->val);
                noteMap[cur]->next = noteMap[cur->next];
            }

            if (cur->random == NULL)
            {
                noteMap[cur]->random = NULL;
            }
            else if (noteMap.find(cur->random) != noteMap.end())
                noteMap[cur]->random = noteMap[cur->random];
            else
            {
                noteMap[cur->random] = new Node(cur->random->val);
                noteMap[cur]->random = noteMap[cur->random];
            }

            cur = cur->next;
        }

        return noteMap[head];
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