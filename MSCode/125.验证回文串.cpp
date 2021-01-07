/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);

        int l = 0, r = s.length() - 1;
        while (l < r)
        {
            for (; (s[l] < '0' || s[l] > '9') && (s[l] < 'a' || s[l] > 'z') && l < r; ++l)
                ;

            for (; (s[r] < '0' || s[r] > '9') && (s[r] < 'a' || s[r] > 'z') && l < r; --r)
                ;
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }
};
// @lc code=end
// "0P"\n