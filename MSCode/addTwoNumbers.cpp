#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
        int len1 = ListLength(l1);
        int len2 = ListLength(l2);
        ListNode *ret = len1 > len2 ? l1 : l2;
        ListNode *pr = ret, *zero = new ListNode(0);
        int count = std::max(len1, len2);
        for (int i = 0; i < count; ++i)
        {
            pr->val = l1->val + l2->val;
            if (pr->val >= 10)
            {
                if (pr->next == NULL)
                {
                    pr->next = new ListNode(1);
                }
                else
                {
                    pr->next->val++;
                }
                pr->val = pr->val - 10;
            }
            else if (l1 == zero || l2 == zero)
            {
                break;
            }

            pr = pr->next;
            l1 = l1->next != NULL ? l1->next : zero;
            l2 = l2->next != NULL ? l2->next : zero;
        }
        delete zero;
        return ret;
    }
    int ListLength(ListNode *ln)
    {
        ListNode *p = ln;
        int len = 0;
        while (p != NULL)
        {
            len++;
            p = p->next;
        }
        return len;
    }
};
// @lc code=end

int main(int argc, char **argv)
{

    return 0;
}