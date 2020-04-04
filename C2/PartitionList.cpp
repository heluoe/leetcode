#include <iostream>
#include <stack>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);

        ListNode *cur = head;
        ListNode *sm_s = NULL, *sm_e = NULL, *la_s = NULL, *la_e = NULL;
        while (cur != NULL)
        {
            if (cur->val < x)
            {
                if (sm_s == NULL)
                {
                    sm_s = cur;
                    sm_e = cur;
                }
                else
                {
                    sm_e->next = cur;
                    sm_e = sm_e->next;
                }
            }
            else
            {
                if (la_s == NULL)
                {
                    la_s = cur;
                    la_e = cur;
                }
                else
                {
                    la_e->next = cur;
                    la_e = la_e->next;
                }
            }
            head = cur;
            cur = cur->next;
            head->next = NULL;
        }

        if (sm_s != NULL && la_s != NULL)
            sm_e->next = la_s;

        return sm_s != NULL ? sm_s : la_s;
    }
};

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    std::uniform_int_distribution<int> uniform_x(0, 15);

    ListNode *head = nullptr;
    ListNode *ptr = nullptr;
    std::vector<int> vals({1, 4, 3, 2, 5, 2});
    std::cout << "Forward link as: ";
    for (int i = 0; i < vals.size(); ++i)
    {
        auto val = vals[i];
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
    int x = 3; //static_cast<int>(std::round(uniform_x(v2)));
    std::cout << " (" << x << ")" << std::endl;
    Solution sol;
    head = sol.partition(head, x);
    std::cout << std::endl
              << "After relink:    ";
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        std::cout << ptr->val << " ";
    }
    std::cout << std::endl;
    return 0;
}
