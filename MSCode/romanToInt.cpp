#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> roman_map;
        roman_map['I'] = 1;
        roman_map['V'] = 5;
        roman_map['X'] = 10;
        roman_map['L'] = 50;
        roman_map['C'] = 100;
        roman_map['D'] = 500;
        roman_map['M'] = 1000;
        unordered_map<string, int> roman_rule;
        roman_rule["IV"] = 4;
        roman_rule["IX"] = 9;
        roman_rule["XL"] = 40;
        roman_rule["XC"] = 90;
        roman_rule["CD"] = 400;
        roman_rule["CM"] = 900;

        string buff = "";
        int result = 0;
        for (char &c : s)
        {
            if (buff == "" || roman_map[buff.back()] >= roman_map[c])
            {
                buff.push_back(c);
            }
            else
            {
                string rule = string(1, buff.back()) + string(1, c);
                if (roman_rule.find(rule) != roman_rule.end())
                {
                    buff.pop_back();
                    for (char &b : buff)
                    {
                        result += roman_map[b];
                    }
                    result += roman_rule[rule];
                    buff = "";
                }
                else
                {
                    buff.push_back(c);
                }
            }
        }
        if (!buff.empty())
        {
            for (char &b : buff)
            {
                result += roman_map[b];
            }
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char **argv)
{
    /*
    "   "III"
    "IIIVXIII"
    */
    Solution sol;
    std::cout << sol.romanToInt("IIIVXIII") << std::endl;

    return 0;
}