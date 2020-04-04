#include <iostream>
#include <stack>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *cur = head, *pre = NULL, *next = NULL;
        while (cur != NULL)
        {
            pre = cur;
            next = cur->next;
            while (next != NULL)
            {
                if (cur->val == next->val)
                {
                    pre->next = next->next;
                    delete next;
                }
                else
                {
                    pre = next;
                }
                next = next->next;
            }
            cur = cur->next;
        }
        return head;
    }
};