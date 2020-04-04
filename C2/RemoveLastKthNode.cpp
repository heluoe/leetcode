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

Node *removeLastKthNode(Node *head, int lastKth)
{
    if (head == nullptr || lastKth < 1)
        return head;
    int K = lastKth;
    Node *ptr = head;
    while (ptr != nullptr)
    {
        K--;
        ptr = ptr->next;
    }
    if (K > 0)
        return head;
    else if (K == 0)
    {
        ptr = head;
        head = ptr->next;
        delete ptr;
    }
    else
    {
        ptr = head;
        while (true)
        {
            K++;
            if (K == 0)
            {
                auto tmp = ptr->next;
                ptr->next = ptr->next->next;
                delete tmp;
                break;
            }
            ptr = ptr->next;
        }
    }

    return head;
}

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(-20, 25);
    std::uniform_int_distribution<int> uniform_len(10, 35);
    std::uniform_int_distribution<int> uniform_k(-1, 15);

    Node *head = nullptr;
    Node *ptr = nullptr;
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
    int K = std::round(uniform_k(v2));
    removeLastKthNode(head, K);
    std::cout << std::endl
              << "After remove:    ";
    for (ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        std::cout << ptr->data << " ";
    }
    std::cout << std::endl
              << "(" << K << "th node) " << std::endl;
}
