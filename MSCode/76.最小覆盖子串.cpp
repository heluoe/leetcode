/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution
{
public:
    bool isCover()
    {
        for (auto &p : s_set)
        {
            if (p.second < t_set[p.first])
                return false;
        }
        return true;
    }
    unordered_map<char, int> t_set, s_set;
    string minWindow(string s, string t)
    {
        if (s.size() < t.size() || t.empty())
            return "";
        string res = "";

        for (const auto c : t)
        {
            t_set[c]++;
        }
        int l = 0, r = 0;
        while (r < s.size())
        {
            if (r - l + 1 >= t.size() && t_set.size() == s_set.size())
            {
                if (isCover())
                {
                    if (res.empty() || res.length() > r - l + 1)
                        res = s.substr(l, r);

                    s_set[s[l]]--;
                    l++;
                }
                else
                {
                    r++;
                }
            }
            else
            {
                char c = s[r];
                if (t_set.find(c) != t_set.end())
                {
                    s_set[c]++;
                }
                ++r;
            }
        }

        return res;
    }
};
// @lc code=end
