/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
            return NULL;

        ListNode *p1 = head, *p2 = head;
        for (int i = 0; i < n; ++i)
        {
            p2 = p2->next;
        }
        if (p2 == NULL) // delete head
        {
            head = head->next;
            delete p1;
        }
        else
        {
            p2 = p2->next;
            while (p2 != NULL)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            p2 = p1->next;
            p1->next = p2->next;
            delete p2;
        }
        return head;
    }
    ListNode *removeNthFromEndTwo(ListNode *head, int n)
    {
        if (head == NULL)
            return NULL;

        stack<ListNode *> stack_buf;
        ListNode *p1 = head;
        while (p1 != NULL)
        {
            stack_buf.push(p1);
            p1 = p1->next;
        }
        p1 = NULL;
        if (n == 1)
        {
            p1 = stack_buf.top();
            stack_buf.pop();
            if (!stack_buf.empty())
                stack_buf.top()->next = NULL;
            else
            {
                head = NULL;
            }

            delete p1;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                p1 = stack_buf.top();
                stack_buf.pop();
            }
            if (stack_buf.empty())
            {
                head = head->next;
                delete p1;
            }
            else
            {
                stack_buf.top()->next = p1->next;
                delete p1;
            }
        }
        return head;
    }
};
// @lc code=end
