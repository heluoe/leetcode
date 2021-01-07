/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        if (path.empty())
            return "";
        if (path.length() < 2)
            return "/";
        string sub_path = "";
        stack<string> stack_path;
        stack_path.push("/");
        for (int i = 1; i < path.length(); ++i)
        {
            if (path[i] == '/' && sub_path == "")
            {
                continue;
            }
            else if (path[i] != '/')
            {
                sub_path += string(1, path[i]);
            }
            else
            {
                if (sub_path == "..")
                {
                    sub_path = "";
                    if (stack_path.size() > 1)
                        stack_path.pop();
                }
                else if (sub_path == ".")
                {
                    sub_path = "";
                    continue;
                }
                else
                {
                    stack_path.push(sub_path);
                    sub_path = "";
                }
            }
        }
        if (!sub_path.empty())
        {

            if (sub_path == "..")
            {
                if (stack_path.size() > 1)
                    stack_path.pop();
            }
            else if (sub_path != "." && sub_path != "..")
                stack_path.push(sub_path);
        }
        sub_path = stack_path.top();
        if (stack_path.size() > 1)
        {
            stack_path.pop();
            while (stack_path.size() > 1)
            {
                sub_path = (stack_path.top() + "/" + sub_path);
                stack_path.pop();
            }
            sub_path = "/" + sub_path;
        }
        //if(path.empty())
        return sub_path;
    }
};
// @lc code=end

// "/../"\n