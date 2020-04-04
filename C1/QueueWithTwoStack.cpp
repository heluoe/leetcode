#include <iostream>
#include <stack>
#include <random>
#include <cmath>

template <typename T>
class QueueTwoStack
{
public:
    T poll()
    {
        if (stackPop_.empty() && stackPush_.empty())
            throw std::runtime_error("The Queue is empty!");

        pushToPop();
        T ret = stackPop_.top();
        stackPop_.pop();
        return ret;
    };
    void add(T val)
    {
        stackPush_.push(val);
    }
    T front()
    {
        if (stackPop_.empty() && stackPush_.empty())
            throw std::runtime_error("The Queue is empty!");

        pushToPop();
        return stackPop_.top();
    }
    bool empty()
    {
        return (stackPop_.empty() && stackPush_.empty());
    }

private:
    void pushToPop()
    {
        if (stackPop_.empty())
        {
            while (!stackPush_.empty())
            {
                T item = stackPush_.top();
                stackPush_.pop();
                stackPop_.push(item);
            }
        }
    }

private:
    std::stack<T> stackPop_;
    std::stack<T> stackPush_;
};
#define DEBUG
int main(int argc, char **argv)
{
    QueueTwoStack<int> testQueue;

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
                std::cout
                    << "Queue in, ";
                auto val = std::round(uniform_dist(v1));
                testQueue.add(val);
#ifdef DEBUG
                auto front = testQueue.front();
                std::cout
                    << val << ", front: " << front << std::endl;
#else
                std::cout
                    << "Queue in, " << val << std::endl;
#endif
            }
            else
            {
                std::cout
                    << "Queue out, ";
                auto val = testQueue.poll();
                std::cout << val;
#ifdef DEBUG
                if (!testQueue.empty())
                {
                    auto front = testQueue.front();
                    std::cout << ", front: " << front << std::endl;
                }
                else
                {
                    std::cout << ", front: NULL" << std::endl;
                }
#else
                std::cout << std::endl;
#endif
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
            continue;
        }
    }

    std::cout << "The Queue :";
    while (!testQueue.empty())
    {
        std::cout << testQueue.poll() << ", ";
    }
    std::cout << std::endl;

    return 0;
}