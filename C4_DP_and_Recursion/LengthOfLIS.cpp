#include <iostream>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
class Solution
{
public:
    int getdp(vector<int> &nums)
    {
        if (nums.size() < 1)
            return 0;

        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
        std::sort(dp.begin(), dp.end(), std::greater<int>());
        return dp[0];
    }
    int getdp2(vector<int> &nums)
    {
        if (nums.size() < 1)
            return 0;

        vector<int> dp(nums.size(), 1);
        vector<int> ends(1, nums[0]);
        for (int i = 1; i < dp.size(); ++i)
        {
            int cur = nums[i];
            auto it = std::find_if(ends.begin(), ends.end(), [&cur](int end) {
                return end >= cur;
            });
            if (it != ends.end())
            {
                auto idx = it - ends.begin();
                *it = cur;
                dp[i] = idx;
            }
            else
            {
                ends.push_back(cur);
            }
        }

        return ends.size();
    }
    int lengthOfLIS(vector<int> &nums)
    {
    }
};