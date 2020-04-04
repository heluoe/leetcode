#include <iostream>
#include <deque>
#include <vector>
#include <random>
#include <cmath>

template <typename T>
class NumSlideWindow
{
private:
    /* data */
    std::deque<size_t> qmax;
    std::deque<size_t> qmin;

public:
    void do_process(const std::vector<T> &arr, T num)
    {
        size_t ret = 0;
        std::cout << "[Do process] find statify with num: " << num << ": " << std::endl;
        for (size_t cur_idx = 0; cur_idx < arr.size(); ++cur_idx)
        {
            for (size_t w = 0; w + cur_idx < arr.size(); ++w)
            {
                while (true)
                {
                    if (qmax.empty() || arr[qmax.back()] > arr[cur_idx + w])
                    {
                        qmax.push_back(cur_idx + w);
                        break;
                    }
                    else if (!qmax.empty())
                    {
                        qmax.pop_back();
                    }
                }
                while (true)
                {
                    if (qmin.empty() || arr[qmin.back()] < arr[cur_idx + w])
                    {
                        qmin.push_back(cur_idx + w);
                        break;
                    }
                    else if (!qmin.empty())
                    {
                        qmin.pop_back();
                    }
                }
                if (arr[qmax.front()] - arr[qmin.front()] <= num)
                {
                    ret++;
                    for (size_t pidx = 0; pidx < arr.size(); ++pidx)
                    {
                        if (cur_idx == pidx)
                            std::cout << "[";
                        std::cout << arr[pidx];
                        if (cur_idx + w == pidx)
                            std::cout << "]";
                        std::cout << " ";
                    }
                    std::cout << " found (" << ret << "): " << arr[qmax.front()] << " - " << arr[qmin.front()] << " <= " << num << std::endl;
                }
                else
                {
                    break;
                }
            }
            // !important cur_idx slide out the min and max element
            if (cur_idx == qmax.front())
                qmax.pop_front();
            if (cur_idx == qmin.front())
                qmin.pop_front();
        }
        std::cout << "result: " << ret << std::endl;
    }
};

int main(int argc, char **argv)
{
    try
    {
        NumSlideWindow<int> slidew;
        std::random_device r;
        std::default_random_engine v1(r());
        std::default_random_engine v2(r());
        std::uniform_int_distribution<int> uniform_dist(-20, 20);
        std::uniform_int_distribution<int> uniform_num(0, 20);
        std::vector<int> arr_data;
        std::cout << "arr data = [ ";
        for (int i = 0; i < 10; ++i)
        {
            auto val = static_cast<int>(std::round(uniform_dist(v1)));
            std::cout << val << " ";
            arr_data.push_back(val);
        }
        std::cout << "]" << std::endl;
        slidew.do_process(arr_data, std::round(uniform_num(v2)));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}