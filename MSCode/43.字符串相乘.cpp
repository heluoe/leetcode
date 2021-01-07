/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        if (num1 == "" || num2 == "")
            return "";

        if (num1.length() < num2.length())
            swap(num1, num2);

        int l1 = num1.length(), l2 = num2.length();
        vector<int> vals(l1 + l2, 0);

        for (int i = l1 - 1; i >= 0; --i)
        {
            for (int j = l2 - 1; j >= 0; --j)
            {
                int val = (num1[i] - '0') * (num2[j] - '0');
                vals[i + j + 1] = val / 10;
                vals[i + j] = val % 10;
            }
        }
        int k = vals.size() - 1;
        for (; k >= 0 && vals[k] != 0; --k)
            ;

        string res = "";
        while (k >= 0)
        {
            res = res + to_string(vals[k]);
            --k;
        }
        return res;
    }
};
// @lc code=end
