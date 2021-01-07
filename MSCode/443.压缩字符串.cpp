/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution
{
public:
    void inline setCountString(vector<char> &chars, int &c, int len)
    {
        string s_count = to_string(len);
        for (const char s : s_count)
        {
            c++;
            chars[c] = s;
        }
    }
    void inline setCount(vector<char> &chars, int &c, int len)
    {

        int l = c + 1;
        while (len > 0)
        {
            int bit = len % 10;
            len /= 10;
            c++;
            chars[c] = '0' + (bit);
        }
        int r = c;
        while (l < r)
        {
            swap(chars[l], chars[r]);
            l++;
            r--;
        }
    }
    int compress(vector<char> &chars)
    {
        int c = 0, len = 1;
        for (int i = 1; i < chars.size(); ++i)
        {
            if (chars[c] == chars[i])
            {
                len++;
            }
            else
            {
                if (len > 1)
                    setCountString(chars, c, len);
                len = 1;
                if (c < i)
                {
                    c++;
                    chars[c] = chars[i];
                }
                else
                {
                    c = i;
                }
            }
        }
        if (len > 1)
        {
            setCountString(chars, c, len);
        }
        return c + 1;
    }
};
// @lc code=end
