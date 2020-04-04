#include <iostream>
#include <stack>
#include <random>
#include <cmath>

template <typename T>
class CMinStack
{
public:
    T pop()
    {
        if (stackData_.empty())
            throw std::runtime_error("The minStack is empty!");
        T ret = stackData_.top();
        stackData_.pop();
        stackMin_.pop();
        return ret;
    };
    void push(T val)
    {
        stackData_.push(val);
        T temMin;
        if (!stackMin_.empty())
        {
            temMin = std::min(stackMin_.top(), val);
        }
        else
        {
            temMin = val;
        }

        stackMin_.push(temMin);
    }
    T getMin()
    {
        if (stackData_.empty())
            throw std::runtime_error("The minStack is empty!");
        return stackMin_.top();
    }
    bool empty()
    {
        return stackData_.empty();
    }
    T top()
    {
        return stackData_.top();
    }

private:
    std::stack<T> stackData_;
    std::stack<T> stackMin_;
};

int main(int argc, char **argv)
{
    CMinStack<int> testStack;
    try
    {
        std::random_device r;
        std::default_random_engine v1(r());
        std::default_random_engine v2(r());
        std::uniform_int_distribution<int> uniform_dist(-1000, 1000);
        std::uniform_int_distribution<int> uniform_bool(0, 2);

        for (int i = 0; i < 15; ++i)
        {
            try
            {
                std::cout << "[Step " << i << "]:  ";

                if (std::round(uniform_bool(v2)) > 0)
                {
                    auto val = std::round(uniform_dist(v1));
                    testStack.push(val);
                    auto min = testStack.getMin();
                    std::cout
                        << "stack push , " << val << ", min: " << min << std::endl;
                }
                else
                {

                    auto val = testStack.pop();
                    std::cout
                        << "stack pop, " << val;
                    if (!testStack.empty())
                    {
                        auto min = testStack.getMin();
                        std::cout << ", min: " << min << std::endl;
                    }
                    else
                    {
                        std::cout << ", min: NULL" << std::endl;
                    }
                }
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
                continue;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "stack :";
    while (!testStack.empty())
    {
        std::cout << testStack.top() << ", ";
        testStack.pop();
    }
    std::cout << std::endl;

    return 0;
}