/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        multiset<pair<int, int>> lines;
        vector<vector<int>> res;
        for (auto &b : buildings)
        {
            lines.insert({b[0], -b[2]});
            lines.insert({b[1], b[2]});
        }
        // store all heigh in current postion
        multiset<int> heights{0};
        // store las possition <x, h>
        vector<int> last = {0, 0};

        for (auto &b : lines)
        {
            if (b.second < 0) // left point of building
                heights.insert(-b.second);
            else
                heights.erase(heights.find(b.second));

            // current point max height
            auto maxHeight = *heights.rbegin();

            if (last[1] != maxHeight)
            {
                // update last and added into result
                last[0] = b.first;
                last[1] = maxHeight;
                res.push_back(last);
            }
        }
        return res;
    }
};
// @lc code=end
// [[0,2,3],[2,5,3]]