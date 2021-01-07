/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        int n1 = listLength(l1);
        int n2 = listLength(l2);

        if (n1 < n2)
            swap(l1, l2);
        int max_len = max(n1, n2);
        int diff_len = abs(n1 - n2);
        ListNode *root = NULL, *p1 = NULL;
        for (int i = 0; i < max_len; ++i)
        {
            p1 = new ListNode(l1->val);
            if (i >= diff_len)
            {
                p1->val += l2->val;
                l2 = l2->next;
            }
            l1 = l1->next;
            p1->next = root;
            root = p1;
        }
        // carry and inverse root
        p1 = root;
        ListNode *p2 = p1->next;
        while (p2 != NULL)
        {
            if (p1->val >= 10)
            {
                p2->val++;
                p1->val -= 10;
            }

            ListNode *p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        root->next = NULL;
        if (p1->val >= 10)
        {
            p2 = new ListNode(1);
            p1->val -= 10;
            p2->next = p1;
            p1 = p2;
        }
        root = p1;
        return root;
    }
    int listLength(ListNode *l)
    {
        int res = 0;
        while (l != NULL)
        {
            res++;
            l = l->next;
        }
        return res;
    }

    int listToNums(ListNode *l1)
    {
        int res = l1->val;
        l1 = l1->next;
        while (l1 != NULL)
        {
            res = res * 10 + l1->val;
            l1 = l1->next;
        }
        return res;
    }
    ListNode *numsToList(int num)
    {
        ListNode *node, *root;
        node = new ListNode(num % 10);
        num /= 10;
        root = node;

        while (num > 0)
        {
            node = new ListNode(num % 10);
            node->next = root;
            root = node;
            num /= 10;
        }
        return root;
    }
};
// @lc code=end
// [7,2,4,2,3,3]\n[9,0,5,6,4]
// [3,9,9,9,9,9,9,9,9,9]\n[7]
// [0]\n[7,3]