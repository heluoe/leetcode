#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <random>
#include <cmath>

class Node
{
public:
    int data;
    Node *next = nullptr;
    Node(int val) : data(val){};
};

Node *DoJosephusKill(Node *head, int m)
{
    if (m < 1 || head->next == head || head == nullptr)
        return head;
    int count = 1;
    Node *ptr = head, *pre = nullptr;
    do
    {
        pre = ptr;
        ptr = ptr->next;
    } while (ptr->next != head);
    ptr = head;
    do
    {
        if (count == m)
        {
            if (ptr == head)
            {
                head = ptr->next;
            }
            std::cout << "Kill :" << ptr->data << std::endl;

            pre->next = ptr->next;
            delete ptr;
            ptr = pre->next;
            count = 1;
        }
        else
        {
            pre = ptr;
            ptr = ptr->next;
            count++;
        }

    } while ((head->next != head));
    return head;
}

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(-20, 25);
    std::uniform_int_distribution<int> uniform_len(1, 15);

    Node *head = nullptr, *ptr = nullptr;
    std::cout << "Forward ring as: ";
    int len = static_cast<int>(std::round(uniform_len(v2)));
    int m = static_cast<int>(std::round(uniform_len(v2)));
    for (int i = 0; i < len; ++i)
    {
        auto val = static_cast<int>(std::round(uniform_dist(v1)));
        if (i == 0)
        {
            head = ptr = new Node(val);
        }
        else
        {
            ptr->next = new Node(val);
            ptr = ptr->next;
        }
        std::cout << val << " ";
    }
    ptr->next = head;

    std::cout << std::endl;
    head = DoJosephusKill(head, m);
    std::cout << std::endl
              << "After remove:    " << head->data;

    std::cout << std::endl
              << "(" << m << ") " << std::endl;
    return 0;
}