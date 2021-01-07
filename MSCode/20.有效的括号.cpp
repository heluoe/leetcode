/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.empty() && s.length() < 2)
            return false;
        unordered_map<char, bool> push_map;
        push_map['('] = true;
        push_map['['] = true;
        push_map['{'] = true;

        push_map[')'] = false;
        push_map[']'] = false;
        push_map['}'] = false;

        string buffer;
        for (char &c : s)
        {
            if (push_map.find(c) == push_map.end())
                return false;
            if (push_map[c])
            {
                buffer.push_back(c);
            }
            else if (!buffer.empty() && !push_map[c])
            {
                const auto t = buffer.back();
                if ((t == '(' && c == ')') || (t == '[' && c == ']') || (t == '{' && c == '}'))
                {
                    buffer.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return buffer.empty();
    }
};
// @lc code=end
