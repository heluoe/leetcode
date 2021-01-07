/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        int lenA = 0;
        int lenB = 0;
        ListNode *n1 = headA, *n2 = headB;
        while (n1 != NULL)
        {
            lenA++;
            n1 = n1->next;
        }
        while (n2 != NULL)
        {
            lenB++;
            n2 = n2->next;
        }
        n1 = lenA > lenB ? headA : headB;
        n2 = n1 == headA ? headB : headA;
        int diff = abs(lenA - lenB);
        for (int i = 0; i < diff; ++i)
            n1 = n1->next;
        while (n1 != NULL)
        {
            if (n1 == n2)
                return n1;
            n1 = n1->next;
            n2 = n2->next;
        }
        return n1;
    }
};
// @lc code=end
