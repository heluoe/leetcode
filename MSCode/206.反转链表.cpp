/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *p1 = head, *p2 = NULL;
        if (p1->next)
            p2 = p1->next;

        while (p2 != NULL)
        {
            ListNode *p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }

        head->next = NULL;
        head = p1;
        return head;
    }
};
// @lc code=end
