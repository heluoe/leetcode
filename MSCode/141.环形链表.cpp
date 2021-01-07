/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }
        ListNode *p1 = head, *p2 = head->next;

        while (p1 != p2)
        {
            p1 = p1->next;
            if (p2 != NULL && p2->next != NULL)
                p2 = p2->next->next;
            else
            {
                p2 = NULL;
            }
        }
        if (p1 == NULL)
            return false;
        else
        {
            return true;
        }
    }
};
// @lc code=end
