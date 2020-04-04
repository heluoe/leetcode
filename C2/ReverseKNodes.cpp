#include <iostream>
#include <stack>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k < 2 || head == NULL)
            return head;
        ListNode *cur = head, *pre = NULL;
        std::stack<ListNode *> rebuf;
        int n = 0;
        while (cur != NULL)
        {
            rebuf.push(cur);
            n++;
            cur = cur->next;
            if (n % k == 0)
            {
                if (n == k)
                {
                    head = rebuf.top();
                }
                ListNode *rev = rebuf.top();
                if (pre != NULL)
                    pre->next = rev;
                rebuf.pop();
                while (!rebuf.empty())
                {
                    rev->next = rebuf.top();
                    rev = rev->next;
                    rebuf.pop();
                }
                pre = rev;
                pre->next = NULL;
            }
        }
        if (pre == NULL)
            return head;
        while (!rebuf.empty())
        {
            cur = rebuf.top();
            rebuf.pop();
        }
        pre->next = cur;
        return head;
    }
};

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    std::uniform_int_distribution<int> uniform_k(6, 18);

    ListNode *head = nullptr;
    ListNode *ptr = nullptr;
    std::cout << "Forward link as: ";
    for (int i = 0; i < static_cast<int>(std::round(uniform_k(v2))); ++i)
    {
        auto val = static_cast<int>(std::round(uniform_dist(v1)));
        if (i == 0)
        {
            head = ptr = new ListNode(val);
        }
        else
        {
            ptr->next = new ListNode(val);
            ptr = ptr->next;
        }
        std::cout << val << " ";
    }
    int K = 4;
    Solution sol;
    head = sol.reverseKGroup(head, K);
    std::cout
        << std::endl
        << "After remove:    ";
    for (ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        std::cout << ptr->val << " ";
    }
    std::cout << std::endl
              << "(" << K << ") " << std::endl;
    return 0;
}