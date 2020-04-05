#include <iostream>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>

/**
 * #325
 */
using namespace std;

class Solution
{
public:
    int maxLenght(vector<int> &arr, int k)
    {
        if (arr.size() < 1)
            return 0;
        unordered_map<int, int> map;
        map[0] = -1;
        int len = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            sum += arr[i];
            if (map.find(sum - k) != map.end())
            {
                //map[sum - k] --> sum(j - 1)
                len = std::max(i - map[sum - k], len);
                std::cout << "sum(j - 1): " << map[sum - k] << std::endl;
                for (int j = 1; j <= len; ++j)
                    std::cout << arr[map[sum - k] + j] << " ";
                std::cout << std::endl;
            }
            if (map.find(sum) == map.end())
            {
                map[sum] = i;
            }
        }
        return len;
    }
};

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(-20, 20);
    std::uniform_int_distribution<int> uniform_k(-20, 20);
    std::uniform_int_distribution<int> uniform_len(10, 45);

    // std::vector<int> arr({-6, -4, 1, 4, -1, 2, -10});
    // int K = 5;
    std::vector<int> arr;
    std::cout << "arr: " << std::endl;
    for (int i = 0; i < static_cast<int>(std::round(uniform_len(v2))); ++i)
    {
        arr.push_back(static_cast<int>(std::round(uniform_dist(v1))));
        std::cout << arr.back() << " ";
    }
    int K = static_cast<int>(std::round(uniform_k(v2)));
    std::cout
        << std::endl
        << "k = " << K << std::endl;
    Solution sol;
    int ret = sol.maxLenght(arr, K);
    std::cout << "ret: " << ret << std::endl;
    return 0;
}