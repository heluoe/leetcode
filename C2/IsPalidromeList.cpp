#include <iostream>
#include <numeric>
#include <stack>
#include <algorithm>
#include <random>
#include <cmath>

class ListNode
{
public:
    int val;
    ListNode *next = NULL;
    ListNode(int data) : val(data), next{NULL} {};
};

bool isPalindrome2(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    auto cur = head;
    auto right = head->next;
    while (cur->next != NULL && cur->next->next != NULL)
    {
        right = right->next;
        cur = cur->next->next;
    }
    cur = right->next;
    right->next = NULL;
    ListNode *nd = NULL;

    while (cur != NULL)
    {
        nd = cur->next;
        cur->next = right;
        right = cur;
        cur = nd;
    }

    while (right != NULL && head != NULL)
    {
        if (right->val != head->val)
            return false;

        right = right->next;
        head = head->next;
    }

    return true;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    auto cur = head;
    auto right = head->next;
    while (cur->next != NULL && cur->next->next != NULL)
    {
        right = right->next;
        cur = cur->next->next;
    }
    std::cout << right->val << " " << right->next->val << std::endl;
    std::stack<int> stack_buf;
    while (right != NULL)
    {
        stack_buf.push(right->val);
        right = right->next;
    }
    right = head;
    std::cout << right->val << " " << right->next->val << std::endl;
    while (!stack_buf.empty())
    {
        if (right->val != stack_buf.top())
            return false;

        std::cout << stack_buf.top() << " ";
        stack_buf.pop();

        right = right->next;
    }
    return true;
}

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(-20, 25);
    std::uniform_int_distribution<int> uniform_len(1, 15);
    std::uniform_int_distribution<int> uniform_bool(1, 15);
    int len = static_cast<int>(std::round(uniform_len(v2)));
    ListNode *head = nullptr, *ptr = nullptr;
    std::stack<int> buff;

    head = new ListNode(static_cast<int>(std::round(uniform_dist(v2))));
    buff.push(head->val);
    ptr = head;
    std::cout << "Forward list as: " << head->val << " ";
    for (int i = 1; i < len; ++i)
    {
        auto val = static_cast<int>(std::round(uniform_dist(v2)));
        ptr->next = new ListNode(val);
        ptr = ptr->next;
        buff.push(val);
        std::cout << val << " ";
    }
    if (static_cast<int>(std::round(uniform_bool(v2))) > 5) //
    {
        if (len % 2 == 0)
            buff.pop();
        while (!buff.empty())
        {
            auto val = buff.top();
            std::cout << val << " ";
            buff.pop();
            ptr->next = new ListNode(val);
            ptr = ptr->next;
        }
    }
    std::cout << std::endl;
    if (isPalindrome(head))
        std::cout << " (true)" << std::endl;
    else
        std::cout << " (false)" << std::endl;
    return 0;
}