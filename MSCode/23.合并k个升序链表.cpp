/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;
        if (lists.size() < 2)
            return lists[0];
        ListNode *result = NULL;
        for (ListNode *l : lists)
        {
            if (result == NULL)
            {
                result = l;
            }
            else
            {
                result = mergeTwoLists(result, l);
            }
        }
        return result;
    }

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
    ListNode *mergeKListsBAD(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;
        ListNode *result;
        ListNode *tail = NULL;
        int min_l = -1;
        for (int i = 0; i < lists.size(); ++i)
        {
            ListNode *l = lists[i];
            if (l != NULL)
            {
                if (tail == NULL)
                {
                    tail = l;
                    min_l = i;
                }
                else if (tail->val > l->val)
                {
                    tail = l;
                    min_l = i;
                }
            }
        }
        result = tail;

        while (min_l != -1)
        {
            lists[min_l] = lists[min_l]->next;
            min_l = -1;
            for (int i = 0; i < lists.size(); ++i)
            {
                ListNode *l = lists[i];
                if (l != NULL)
                {
                    if (min_l == -1)
                    {
                        tail->next = l;
                        min_l = i;
                    }
                    else if (lists[min_l]->val > l->val)
                    {
                        min_l = i;
                        tail->next = l;
                    }
                }
            }
            if (min_l != -1)
                tail = tail->next;
        }
        return result;
    }
};
// @lc code=end
