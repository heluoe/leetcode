/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> alpha, beta;
        for (const auto &c : s1)
            alpha[c]++;

        int l = 0, r = 0;
        while (r < s2.size())
        {
        }
    }

    bool checkInclusionSlideWindow(string s1, string s2)
    {
        unordered_map<char, int> mp;
        for (auto &c : s1)
            mp[c]++; // 记录 出现次数的差值

        int l = 0, r = 0;
        while (r < s2.size())
        {
            char c = s2[r++];
            mp[c]--; // 入窗
            while (l < r && mp[c] < 0)
            { // 出窗
                mp[s2[l++]]++;
            }
            if (r - l == s1.size())
                return true;
        }
        return false;
    }
    bool checkInclusionBAD(string s1, string s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        if (s2.empty() || l1 > l2)
            return false;
        if (s1.empty())
            return true;

        vector<int> alpha(26, 0);
        for (const auto c : s1)
        {
            alpha[c - 'a']++;
        }

        for (int i = 0; i + l1 - 1 < l2; ++i)
        {
            vector<int> beta(26, 0);
            string ss = s2.substr(i, l1);
            for (const auto c : ss)
            {
                beta[c - 'a']++;
            }
            bool result = true;
            for (int j = 0; j < 26 && result; ++j)
            {
                if (beta[j] != alpha[j])
                    result = false;
            }
            if (result)
                return result;
        }
        return false;
    }
};
// @lc code=end
//"adc"\n"dcda"