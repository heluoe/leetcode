#include <iostream>
#include <deque>
#include <vector>
#include <random>
#include <cmath>

template <typename T>
class MaxSlideWindow
{
private:
    /* data */
    std::deque<T> qmax;

public:
    void do_process(const std::vector<T> &arr, T w)
    {
        if (arr.size() < static_cast<size_t>(w))
            throw std::runtime_error("NULL by wrong window size!");

        std::cout << "[Do process] with w size " << w << ": " << std::endl;
        for (auto cur_idx = 0; cur_idx < arr.size(); ++cur_idx)
        {
            if (!qmax.empty() && (qmax.front() + w - 1) < cur_idx)
            {
                qmax.pop_front();
            }
            while (true)
            {
                if (qmax.empty() || arr[qmax.back()] > arr[cur_idx])
                {
                    qmax.push_back(cur_idx);
                    break;
                }
                else if (!qmax.empty())
                {
                    qmax.pop_back();
                }
            }
            if (cur_idx >= w - 1)
            {
                for (auto pidx = 0; pidx < arr.size(); ++pidx)
                {
                    if ((cur_idx - w + 1) == pidx)
                        std::cout << "[";
                    std::cout << arr[pidx];
                    if (cur_idx == pidx)
                        std::cout << "]";
                    std::cout << " ";
                }
                std::cout << " the maxval in sildewindow is: " << arr[qmax.front()] << std::endl;
            }
        }
    }
};

int main(int argc, char **argv)
{
    try
    {
        MaxSlideWindow<int> slidew;
        std::random_device r;
        std::default_random_engine v1(r());
        std::default_random_engine v2(r());
        std::uniform_int_distribution<int> uniform_dist(-1000, 1000);

        std::vector<int> arr_data;
        for (int i = 0; i < 35; ++i)
        {
            auto val = static_cast<int>(std::round(uniform_dist(v1)));
            arr_data.push_back(val);
        }
        std::uniform_int_distribution<int> uniform_w(1, arr_data.size());
        slidew.do_process(arr_data, static_cast<int>(std::round(uniform_w(v2))));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}