/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution
{
public:
    vector<int> getPrimeArray()
    {
        vector<int> vec;
        int idx = 3;
        // vec.push_back(1);
        while (true)
        {
            if (vec.size() == 26)
                break;

            idx++;
            bool is_prime = true;
            for (int i = 2; i * i <= idx && is_prime; ++i)
            {
                if (idx % i == 0)
                    is_prime = false;
            }
            if (is_prime)
                vec.push_back(idx);
        }

        return vec;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<double, vector<string>> word_maps;
        vector<int> pkey = getPrimeArray();

        for (const string &s : strs)
        {
            double key = 1;
            for (const char c : s)
            {
                key *= static_cast<double>(pkey[(c - 'a')]);
            }
            if (word_maps.find(key) != word_maps.end())
            {
                word_maps[key].push_back(s);
            }
            else
            {
                vector<string> new_word;
                new_word.push_back(s);
                word_maps[key] = new_word;
            }
        }
        vector<vector<string>> res;
        for (const auto &ws : word_maps)
        {
            res.push_back(ws.second);
        }
        return res;
    }

    vector<vector<string>> groupAnagramsSlow(vector<string> &strs)
    {
        vector<vector<string>> res;
        if (strs.size() < 2)
        {
            res.push_back(strs);
            return res;
        }

        sort(strs.begin(), strs.end(), [](string &a, string &b) {
            return a.length() < b.length();
        });

        vector<int> vec_words(26, 0);
        for (const char c : strs[0])
        {
            vec_words[c - 'a']++;
        }
        string key = "";
        for (int i = 0; i < 26; ++i)
        {
            key = key + string(1, i + 'a') + to_string(vec_words[i]);
        }
        unordered_map<string, int> maps;
        maps[key] = 0;

        vector<string> words;
        words.push_back(strs[0]);
        res.push_back(words);

        for (int i = 1; i < strs.size(); ++i)
        {
            string &s = strs[i];
            vector<int> w(26, 0);
            for (const char c : s)
            {
                w[c - 'a']++;
            }
            key = "";
            for (int i = 0; i < 26; ++i)
            {
                key = key + string(1, i + 'a') + to_string(w[i]);
            }
            if (strs[i - 1].length() != s.length())
            {
                words.clear();
                words.push_back(s);
                res.push_back(words);
                maps[key] = res.size() - 1;
            }
            else
            {
                if (maps.find(key) != maps.end())
                {
                    res[maps[key]].push_back(s);
                }
                else
                {
                    words.clear();
                    words.push_back(s);
                    res.push_back(words);
                    maps[key] = res.size() - 1;
                }
            }
        }
        return res;
    }
};

// @lc code=end
