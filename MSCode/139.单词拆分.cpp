/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (s.empty() || wordDict.empty())
            return false;

        unordered_set<string> word_maps;
        for (const string &ws : wordDict)
        {
            word_maps.insert(ws);
        }
        // dp[i] -> s[0..i−1]
        // dp[i] = dp[j] (s[0..j-1]) && find(s[j..i−1])
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && word_maps.find(s.substr(j, i - j)) != word_maps.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }

    struct TrieNode
    {
        bool is_word = false;
        shared_ptr<TrieNode> childs[26];
    };

    bool bfs(string &s, shared_ptr<TrieNode> node, int idx)
    {
        if (idx >= s.length())
            return node->is_word;
        node = node->childs[s[idx] - 'a'];
        if (node != nullptr)
        {
            if (node->is_word)
                return (bfs(s, node, idx + 1) || bfs(s, root_, idx + 1));
            else
                return bfs(s, node, idx + 1);
        }

        return false;
    }

    bool wordBreakTLE(string s, vector<string> &wordDict)
    {
        if (s.empty() || wordDict.empty())
            return false;

        root_ = make_shared<TrieNode>();
        for (int i = 0; i < 26; ++i)
            root_->childs[i] = nullptr;

        for (const string &ws : wordDict)
        {
            shared_ptr<TrieNode> p = root_;
            for (const char c : ws)
            {
                if (p->childs[c - 'a'] == nullptr)
                {
                    p->childs[c - 'a'] = make_shared<TrieNode>();
                    for (int i = 0; i < 26; ++i)
                        p->childs[c - 'a']->childs[i] = nullptr;
                }
                p = p->childs[c - 'a'];
            }
            p->is_word = true;
        }

        return bfs(s, root_, 0);
    }
    shared_ptr<TrieNode> root_;
};
// @lc code=end

// "applepenapple"\n["apple", "pen"]
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]
// "abcd"\n["a","abc","b","cd"]
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"\n["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]