/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;

        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        vector<int> dp(points.size(), 1);

        vector<int> ext_x = points[0];
        for (int i = 1; i < points.size(); ++i)
        {
            const auto &p = points[i];
            if (p[0] <= ext_x[1])
            {
                ext_x[0] = p[0];
                ext_x[1] = min(p[1], ext_x[1]);
                dp[i] = dp[i - 1];
            }
            else
            {
                ext_x = points[i];
                dp[i] = dp[i - 1] + 1;
            }
        }
        return dp.back();
    }
};
// @lc code=end
