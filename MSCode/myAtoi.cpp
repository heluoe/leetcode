#include <string>
#include <iostream>
#include <limits.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string str)
    {
        if (str.length() == 0)
            return 0;
        int abs = 1, ret = 0;
        string buff = "";
        string smin = "2147483648";
        string smax = "2147483647";
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == ' ' && buff == "")
            {
                continue;
            }
            else if (buff == "" && (str[i] == '-' || str[i] == '+'))
            {
                abs = str[i] == '-' ? -1 : 1;
                if (i + 1 < str.length() && (str[i + 1] > '9' || str[i + 1] < '0'))
                    return 0;
            }
            else if (buff == "" && str[i] == '0')
            {
                if (i + 1 < str.length() && (str[i + 1] > '9' || str[i + 1] < '0'))
                    break;
            }
            else if ('0' <= str[i] && str[i] <= '9')
            {
                buff.push_back(str[i]);
                if (buff.length() == smax.length())
                {
                    if (abs == 1 && buff >= smax)
                        return INT_MAX;
                    else if (abs == -1 && buff >= smin)
                        return INT_MIN;
                }
                else if (buff.length() > smax.length())
                {
                    return abs == 1 ? INT_MAX : INT_MIN;
                }
            }
            else
            {
                break;
            }
        }
        int count = buff.length();
        for (int i = 0; i < count; ++i)
        {
            int num = static_cast<int>(buff[i] - '0');
            ret = ret * 10 + num;
        }

        return ret * abs;
    }
};
// @lc code=end

int main(int argc, char **argv)
{
    /*
    "   -42"\n
    "   +0 123"\n
    "          +0000000000000000000000000012345678"
    "a"
    */
    Solution sol;
    std::cout << sol.myAtoi("2147483648") << std::endl;

    return 0;
}