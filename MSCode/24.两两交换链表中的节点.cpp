/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        ListNode *result = p2;
        while (p1 != NULL && p2 != NULL)
        {
            ListNode *tmp = p2->next;
            p2->next = p1;
            p1->next = tmp;
            p1 = p1->next;
            if (p1 != NULL)
            {
                if (p1->next != NULL)
                {
                    p2->next->next = p1->next;
                    p2 = p1->next;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return result;
    }
};
// @lc code=end
