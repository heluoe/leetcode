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

Node *reverseList(Node *head)
{
    Node *pre = nullptr, *next = nullptr;
    while (head != nullptr)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(-20, 25);
    std::uniform_int_distribution<int> uniform_len(10, 35);

    Node *head = nullptr, *ptr = nullptr;
    std::cout << "Forward link as: ";
    for (int i = 0; i < static_cast<int>(std::round(uniform_len(v2))); ++i)
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
    head = reverseList(head);
    std::cout << std::endl
              << "After reverse:    ";
    for (ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        std::cout << ptr->data << " ";
    }
    std::cout << std::endl;
}