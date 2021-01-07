/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        if (version1.empty() && version2.empty())
            return 0;
        int i1 = 0, i2 = 0;
        int result = 0;
        string ver1 = "", ver2 = "";
        int i_ver1 = 0, i_ver2 = 0;
        vector<int> vec_ver1, vec_ver2;
        while (true)
        {
            for (; version1[i1] == '0' && ver1.empty(); ++i1)
                ;
            if (i1 >= version1.length())
                break;
            if (version1[i1] != '.')
            {
                ver1 = ver1 + string(1, version1[i1]);
            }
            else
            {
                for (int i = 0; i < ver1.length(); ++i)
                {
                    i_ver1 = i_ver1 * 10 + (ver1[i] - '0');
                }
                vec_ver1.push_back(i_ver1);
                ver1 = "";
                i_ver1 = 0;
            }
            i1++;
        }
        while (true)
        {
            for (; version2[i2] == '0' && ver2.empty(); ++i2)
                ;
            if (i2 >= version2.length())
                break;
            if (version2[i2] != '.')
            {
                ver2 = ver2 + string(1, version2[i2]);
            }
            else
            {
                for (int i = 0; i < ver2.length(); ++i)
                {
                    i_ver2 = i_ver2 * 10 + (ver2[i] - '0');
                }
                vec_ver2.push_back(i_ver2);
                ver2 = "";
                i_ver2 = 0;
            }
            i2++;
        }
        i_ver1 = 0;
        i_ver2 = 0;
        for (int i = 0; i < ver1.length(); ++i)
        {
            i_ver1 = i_ver1 * 10 + (ver1[i] - '0');
        }
        vec_ver1.push_back(i_ver1);
        for (int i = 0; i < ver2.length(); ++i)
        {
            i_ver2 = i_ver2 * 10 + (ver2[i] - '0');
        }
        vec_ver2.push_back(i_ver2);
        int inverse = 1;
        if (vec_ver1.size() < vec_ver2.size())
        {
            swap(vec_ver1, vec_ver2);
            inverse = -1;
        }

        for (int i = 0; i < vec_ver1.size(); ++i)
        {
            if (i < vec_ver2.size())
            {
                if (vec_ver1[i] != vec_ver2[i])
                    return vec_ver1[i] < vec_ver2[i] ? -1 * inverse : 1 * inverse;
            }
            else if (vec_ver1[i] > 0)
                return 1 * inverse;
        }
        return 0;
    }
};
// @lc code=end
// "1.0.1"\n  "1"\n
// "7.5.2.4"\n"7.5.3"\n
// "1.0"\n"1.0.0.0.0.0"\n
// "1.01"\n"1.001"\n
// "0.1"\n"1.1"\n
// "1.0"\n"1.0.0"\n
// "1"\n"1.1"\n