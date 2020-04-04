#include <iostream>
#include <stack>
#include <vector>
#include <random>
#include <cmath>
#include <string>
#include <map>

//exist repeat nums
void getNearLessNeigborRepeat(const std::vector<int> &arr)
{
    std::vector<std::pair<int, int>> ans(arr.size(), {-1, -1});
    std::stack<std::vector<int>> stackBuf;
    std::cout << "Do process: GetNearLessNeighbor with repeat nums:" << std::endl
              << "arr = {";
    for (size_t idx = 0; idx < arr.size(); ++idx)
    {
        std::cout << arr[idx];
        if (idx != arr.size() - 1)
            std::cout << ",";

        std::vector<int> itr_top;
        while (!stackBuf.empty() && arr[idx] < arr[stackBuf.top().back()])
        {
            itr_top = stackBuf.top();
            stackBuf.pop();
            for (auto itr_idx : itr_top)
                ans[itr_idx].second = idx;

            if (!stackBuf.empty())
            {
                for (auto itr_idx : itr_top)
                    ans[itr_idx].first = stackBuf.top().back();
                itr_top = stackBuf.top();
            }
        }
        if (stackBuf.empty() || arr[idx] > arr[stackBuf.top().front()])
        {
            stackBuf.push(std::vector<int>({idx}));
        }
        else
        {
            stackBuf.top().push_back(idx);
        }
    }
    while (stackBuf.size() > 1)
    {
        auto itr_top = stackBuf.top();
        stackBuf.pop();
        for (auto itr_idx : itr_top)
            ans[itr_idx].first = stackBuf.top().back();
    }
    std::cout << "}" << std::endl
              << "{" << std::endl;
    for (size_t idx = 0; idx < arr.size(); ++idx)
    {
        const auto &val = ans[idx];

        auto ans_l = (val.first == -1 ? "NULL" : std::to_string(arr[val.first]));
        auto ans_r = (val.second == -1 ? "NULL" : std::to_string(arr[val.second]));
        std::cout << "    {" << val.first << "," << val.second
                  << "}";
        if (idx != arr.size() - 1)
            std::cout << ", ";
        std::cout << "  //{" << ans_l << "," << ans_r << "} :" << arr[idx] << std::endl;
    }
    std::cout << "}" << std::endl;
}

// no repeat nums
void getNearLessNeighbor(const std::vector<int> &arr)
{
    std::vector<std::pair<int, int>> ans(arr.size(), {-1, -1});
    std::stack<int> stackBuf;
    std::cout << "Do process: GetNearLessNeighbor with no repeat nums:" << std::endl
              << "arr = {";

    for (size_t idx = 0; idx < arr.size(); ++idx)
    {
        std::cout << arr[idx];
        if (idx != arr.size() - 1)
            std::cout << ",";

        if (stackBuf.empty() || arr[idx] > arr[stackBuf.top()])
        {
            stackBuf.push(idx);
            continue;
        }

        auto itr_top = stackBuf.top();
        while (arr[idx] < arr[itr_top])
        {
            stackBuf.pop();
            ans[itr_top].second = idx;
            if (!stackBuf.empty())
            {
                ans[itr_top].first = stackBuf.top();
                itr_top = stackBuf.top();
            }
            else
                break;
        }
        stackBuf.push(idx);
    }
    while (stackBuf.size() > 1)
    {
        auto itr_top = stackBuf.top();
        stackBuf.pop();
        ans[itr_top].first = stackBuf.top();
    }
    std::cout << "}" << std::endl
              << "{" << std::endl;
    for (size_t idx = 0; idx < arr.size(); ++idx)
    {
        const auto &val = ans[idx];

        auto ans_l = (val.first == -1 ? "NULL" : std::to_string(arr[val.first]));
        auto ans_r = (val.second == -1 ? "NULL" : std::to_string(arr[val.second]));
        std::cout << "    {" << val.first << "," << val.second
                  << "}";
        if (idx != arr.size() - 1)
            std::cout << ", ";
        std::cout << "  //{" << ans_l << "," << ans_r << "} :" << arr[idx] << std::endl;
    }
    std::cout << "}" << std::endl;
}

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(1, 1000);
    std::uniform_int_distribution<int> uniform_repeat(0, 7);
    std::map<int, int> norepeat;
    std::vector<int> arr_data1, arr_data2;
    int total = 15;
    for (int i = 0; i < total; ++i)
    {
        auto val = static_cast<int>(std::round(uniform_dist(v1)));
        if (norepeat.find(val) == norepeat.end())
        {
            arr_data1.push_back(val);
            norepeat[val] = val;
        }
        val = static_cast<int>(std::round(uniform_repeat(v2)));
        arr_data2.push_back(val);
    }
    try
    {
        // arr_data = std::vector<int>({-392, -848, -255, -108, -150, -418, 476, -286, 148, -575, 308, 717, 968, -569, 46});
        getNearLessNeighbor(arr_data1);
        getNearLessNeigborRepeat(arr_data2);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}