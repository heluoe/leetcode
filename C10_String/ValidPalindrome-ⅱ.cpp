#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution
{
public:
    bool validPalindrome(string s)
    {
        if (s.length() < 1)
            return true;
        int begin = 0, end = s.length() - 1;
        for (int i = 0; i < s.length() / 2; ++i)
        {
            if (s[begin] == s[end])
            {
                begin++;
                end--;
            }
            else
            {
                return (do_process(s.length() / 2, begin + 1, end, s) || do_process(s.length() / 2, begin, end - 1, s));
            }
        }
        return true;
    }
    bool do_process(int mid, int begin, int end, string &s)
    {
        while (true)
        {
            if (s[begin] != s[end])
                return false;
            else
            {
                begin++;
                end--;
            }
            if (begin >= mid || end <= mid)
                return true;
        }
        return true;
    }
};
// @lc code=end

/*
"abc"
*/