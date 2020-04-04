#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
#include <random>
#include <cmath>

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(-20, 25);
    std::uniform_int_distribution<int> uniform_len(10, 35);
    std::list<int> num1, num2;
    for (int i = 0; i < static_cast<int>(std::round(uniform_len(v2))); ++i)
    {
        num1.push_back(static_cast<int>(std::round(uniform_dist(v1))));
    }
    num1.sort();
    for (int i = 0; i < static_cast<int>(std::round(uniform_len(v2))); ++i)
    {
        num2.push_back(static_cast<int>(std::round(uniform_dist(v1))));
    }
    num2.sort();
    std::cout << "list 1: ";
    for (auto &it : num1)
        std::cout << it << " ";
    std::cout << std::endl;
    std::cout << "list 2: ";
    for (auto &it : num2)
        std::cout << it << " ";
    std::cout << std::endl;
    auto head1 = num1.begin();
    auto head2 = num2.begin();
    std::cout << "do common process: ";
    while (head1 != num1.end() && head2 != num2.end())
    {
        if (*head1 < *head2)
        {
            head1++;
        }
        else if (*head1 == *head2)
        {
            std::cout << *head1 << ",";
            head1++;
            head2++;
        }
        else
        {
            head2++;
        }
    }
    std::cout << std::endl;
}