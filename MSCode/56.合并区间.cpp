/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty() || intervals.size() < 2)
            return intervals;
        vector<vector<int>> results;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> b) {
            return a[0] < b[0];
        });
        vector<int> vec_merge(2);
        vec_merge = intervals[0];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (vec_merge[1] < intervals[i][0])
            {
                if (results.empty())
                    results.push_back(vec_merge);

                results.push_back(intervals[i]);
                vec_merge = intervals[i];
            }
            else
            {
                vec_merge[1] = max(vec_merge[1], intervals[i][1]);
                if (results.empty())
                {
                    results.push_back(vec_merge);
                }
                else
                {
                    results.back() = vec_merge;
                }
            }
        }
        return results;
    }
};
// @lc code=end

//[[1,4],[5,6]]\n
