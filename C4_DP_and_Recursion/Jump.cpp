#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.empty() || nums.size() == 1)
            return 0;

        int dp[2] = {0, 0}; // {current jump, next jump}
        int jump = 0;
        for (int i = 0; i < nums.size(); ++i)
        {

            if (dp[0] < i)
            {
                jump++;
                dp[0] = dp[1];
            }
            dp[1] = std::max(dp[1], nums[i] + i);
        }
        return jump;
    }
};
// @lc code=end

/*
[1,1,2,1,1]
[2,3,1,1,4]
*/
