#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        if (envelopes.size() < 1)
            return 0;
        std::sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] < b[0])
                return true;
            else if (a[0] == b[0])
            {
                return a[1] > b[1];
            }
            else
            {
                return false;
            }
        });

        vector<int> dp(envelopes.size(), 1);
        vector<int> ends(1, envelopes[0][1]);
        for (size_t i = 1; i < dp.size(); ++i)
        {

            int cur = envelopes[i][1];
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
};

// @lc code=end

int main(int argc, char **argv)
{
    // [[46,89],[50,53],[52,68],[72,45],[77,81]] 3
    // [[5,4],[6,4],[6,7],[2,3]] 3
    // [[4,5],[4,6],[6,7],[2,3],[1,1]]  4
    //std::vector<vector<int>> vec({{5, 4}, {6, 4}, {6, 7}, {2, 3}});
    std::vector<vector<int>> vec({{5, 4}, {6, 4}, {6, 7}, {2, 3}});
    Solution sol;
    std::cout << sol.maxEnvelopes(vec) << std::endl;
    return 0;
}
