/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *p1 = l1->val <= l2->val ? l1 : l2;
        ListNode *p2 = p1 == l1 ? l2 : l1;
        ListNode *result = p1;
        ListNode *tail = p1;
        p1 = p1->next;
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val <= p2->val)
            {
                tail->next = p1;
                tail = p1;
                p1 = p1->next;
            }
            else
            {
                tail->next = p2;
                tail = p2;
                p2 = p2->next;
            }
        }
        if (p1 != NULL)
            tail->next = p1;
        if (p2 != NULL)
            tail->next = p2;
        return result;
    }
};
// @lc code=end
