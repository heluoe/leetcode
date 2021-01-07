/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        string result;
        stack<string> words;
        string word;
        for (int i = 0; i < s.length(); ++i)
        {

            if (s[i] == ' ' && word == "")
            {
                continue;
            }
            else if (s[i] == ' ')
            {
                words.push(word);
                word = "";
            }
            else
            {
                word = word + string(1, s[i]);
            }
        }
        if (!word.empty())
            words.push(word);
        while (!words.empty())
        {
            if (words.size() > 1)
                result = (result + words.top() + " ");
            else
                result += words.top();

            words.pop();
        }
        return result;
    }
};
// @lc code=end
