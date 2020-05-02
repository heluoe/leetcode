#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() < 1)
      return 0;
    int s_start = 0, ret = 1;
    unordered_map<char, int> char_map;
    char_map[s.at(0)] = 0;
    for (int i = 1; i < s.length(); ++i) {
      auto cur = s.at(i);

      if (char_map.find(cur) != char_map.end() &&
          (char_map[cur] >= s_start && char_map[cur] <= i - 1)) {

        if (i - 1 == char_map[cur]) {
          s_start = i;

        } else {
          s_start = char_map[cur] + 1;
        }
      }
      char_map[cur] = i;
      ret = std::max(ret, i - s_start + 1);
    }
    return ret;
  }
};
// @lc code=end
