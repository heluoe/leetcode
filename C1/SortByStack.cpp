#include <iostream>
#include <stack>
#include <random>
#include <cmath>

int main(int argc, char **argv)
{

    std::random_device r;
    std::default_random_engine v1(r());
    std::uniform_int_distribution<int> uniform_dist(-1000, 1000);

    std::stack<int> data_vals, sort_buf;

    std::cout << "Prepare data: ";
    for (int i = 0; i < 25; ++i)
    {
        auto val = std::round(uniform_dist(v1));
        data_vals.push(val);
        std::cout << val << " ";
    }
    std::cout << std::endl;

    //
    while (!data_vals.empty())
    {
        auto cur = data_vals.top();
        data_vals.pop();
        if (sort_buf.empty() || cur >= sort_buf.top())
        {
            sort_buf.push(cur);
        }
        else
        {
            while (!sort_buf.empty() && cur < sort_buf.top())
            {
                data_vals.push(sort_buf.top());
                sort_buf.pop();
            }
            data_vals.push(cur);
        }
    }

    std::cout << "Sorted data: ";
    while (!sort_buf.empty())
    {
        std::cout << sort_buf.top() << " ";
        sort_buf.pop();
    }
    std::cout << std::endl;

    return 0;
}