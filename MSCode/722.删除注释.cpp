/*
 * @lc app=leetcode.cn id=722 lang=cpp
 *
 * [722] 删除注释
 */

// @lc code=start
class Solution
{
public:
    vector<string> removeComments(vector<string> &source)
    {
        if (source.empty())
            return source;
        vector<string> res;
        bool is_block = false;
        string l;
        for (string &line : source)
        {
            for (int i = 0; i < line.length(); ++i)
            {
                if (!is_block && line[i] == '/' && i + 1 < line.length())
                {
                    if (line[i + 1] == '/')
                    {
                        i++;
                        break;
                    }
                    else if (line[i + 1] == '*')
                    {
                        i++;
                        is_block = true;
                        continue;
                    }
                }
                else if (is_block)
                {
                    if (line[i] == '*' && i + 1 < line.length())
                    {
                        if (line[i + 1] == '/')
                        {
                            is_block = false;
                            i++;
                        }
                    }
                    continue;
                }
                l += string(1, line[i]);
            }
            if (!l.empty() && !is_block)
            {
                res.push_back(l);
                l = "";
            }
        }
        return res;
    }
};
// @lc code=end
// ["struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};"]