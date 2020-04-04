
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);
        if (intervals.size() < 2)
            return intervals;
        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        vector<vector<int>> rets;
        for (size_t i = 0; i < intervals.size(); ++i)
        {
            vector<int> ret = intervals[i];
            size_t j = i + 1;
            for (; j < intervals.size(); ++j)
            {
                if (ret[1] <= intervals[j][1] && ret[1] >= intervals[j][0])
                    ret[1] = intervals[j][1];
                else if (ret[1] < intervals[j][0])
                    break;
            }
            rets.emplace_back(std::move(ret));
            i = j - 1;
        }
        return rets;
    }
};

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    std::uniform_int_distribution<int> uniform_x(0, 15);

    vector<vector<int>> intervals({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    Solution sol;
    auto ret = sol.merge(intervals);
    std::cout << "Ret: " << std::endl
              << "[";
    for (auto vec : ret)
    {
        std::cout << "[" << vec[0] << "," << vec[1] << "] ";
    }
    std::cout << "]" << std::endl;
    return 0;
}