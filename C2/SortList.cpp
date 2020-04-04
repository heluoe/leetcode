
#include <iostream>
#include <limits>
#include <random>
#include <algorithm>
#include <cmath>

/**
 * Definition for singly-linked list.
 *  
 * */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // O(n^2) Time Limit Exceeded
    ListNode *selectSort(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *cur = head, *Newhead = NULL, *Newtail = NULL, *small_pre = NULL, *small;
        while (cur != NULL)
        {
            small = head;
            for (small_pre = head; small_pre != NULL; small_pre = small_pre->next)
            {
                if (small->val > small_pre->val)
                {
                    small = small_pre;
                }
            }
            if (Newhead == NULL)
            {
                Newhead = new ListNode(small->val);
                Newtail = Newhead;
            }
            else
            {
                Newtail->next = new ListNode(small->val);
                Newtail = Newtail->next;
            }
            small->val = std::numeric_limits<int>::max();
            cur = cur->next;
        }
        return Newhead;
    }

    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val < l2->val)
        {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge(l1, l2->next);
            return l2;
        }
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