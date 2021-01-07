#include <iostream>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.empty() && !needle.empty())
        {
            return -1;
        }
        if (needle.empty())
        {
            return 0;
        }
        int result = -1;
        int nlen = needle.length();
        for (int s1 = 0; s1 + nlen - 1 < haystack.length(); ++s1)
        {
            int s2 = 0;
            for (; s2 < nlen; ++s2)
            {
                if (haystack[s1 + s2] != needle[s2])
                {
                    break;
                }
            }
            if (s2 == nlen)
            {
                result = s1;
                break;
            }
        }

        return result;
    }
};
// @lc code=end

// "hello"\n"ll"\n
// "mississippi"\n"a"\n
// "mississippi"\n"issi"\n
// "mississippi"\n"issip"\n

int main(int argc, char **argv)
{
    Solution sol;
    std::cout << sol.strStr("mississippi", "issip") << std::endl;

    return 0;
}