/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        if(A.empty())
            return {};
        
        unordered_map<char, int> char_maps;
        for(const auto c : A[0])
            char_maps[c]++;

        for(int i = 1; i<A.size(); ++i)
        {
            unordered_map<char, int> maps;
            for(const auto c : A[i])
            {
               if(char_maps.find(c) != char_maps.end())
               {
                    maps[c]++;
                    maps[c] = min(char_maps[c], maps[c]);
               }
            }
            swap(maps, char_maps);
        }
        vector<string> res;
        for(const auto & p : char_maps)
        {
            for(int i = 0; i<p.second; ++i)
                res.push_back(string(1, p.first));
        }
        return res;
    }
};
// @lc code=end

