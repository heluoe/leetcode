/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        if (s.empty())
            return -1;
        if (s.size() < 2)
            return 0;

        unordered_map<char, bool> s_map;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s_map.find(s[i]) == s_map.end())
                s_map[s[i]] = true;
            else
            {
                s_map[s[i]] = false;
            }
        }
        for (int i = 0; i < s.length(); ++i)
        {
            if (s_map[s[i]])
                return i;
        }
        return -1;
    }
};
// @lc code=end
