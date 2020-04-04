#include <iostream>
#include <stack>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

/**
 * Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getTheLoopNode(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return NULL;

        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while (slow != fast)
        {
            if (slow->next == NULL || fast->next == NULL || fast->next->next == NULL)
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *getIntersection(ListNode *headA, ListNode *headB, ListNode *endA, ListNode *endB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode *curA = headA, *curB = headB;
        int diffN = 0;
        while (curA->next != endA)
        {
            curA = curA->next;
            diffN++;
        }
        while (curB->next != endB)
        {
            curB = curB->next;
            diffN--;
        }
        if (curA != curB)
            return NULL;
        curA = diffN >= 0 ? headA : headB;
        curB = diffN >= 0 ? headB : headA;
        diffN = std::abs(diffN);
        for (int i = 0; i < diffN; ++i)
        {
            curA = curA->next;
        }
        while (curA != curB)
        {
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *loopA = getTheLoopNode(headA);
        ListNode *loopB = getTheLoopNode(headB);
        if ((loopA == NULL && loopB != NULL) || (loopB == NULL && loopA != NULL))
            return NULL;
        if (loopA == NULL && loopB == NULL)
            return getIntersection(headA, headB, NULL, NULL);
        if (loopA == loopB)
        {
            return getIntersection(headA, headB, loopA, loopB);
        }
        else
        {
            ListNode *cur = loopA;
            do
            {
                if (cur == loopB)
                    return loopB;
                cur = cur->next;
            } while (cur != loopA);
            return NULL;
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