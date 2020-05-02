#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
  int minDistance(string word1, string word2) {
    if (word1.empty() && word2.empty())
      return 0;
    if (word1.empty() && !word2.empty())
      return word2.length();

    if (!word1.empty() && word2.empty())
      return word1.length();

    vector<vector<int>> dp(word1.length() + 1,
                           vector<int>(word2.length() + 1, 0));
    for (int i = 1; i <= word2.length(); ++i) {
      dp[0][i] = i;
    }
    for (int i = 1; i <= word1.length(); ++i) {
      dp[i][0] = i;
    }
    for (int i = 1; i < word1.length() + 1; ++i) {
      for (int j = 1; j < word2.length() + 1; ++j) {
        int left = dp[i - 1][j] + 1;
        int down = dp[i][j - 1] + 1;
        int left_down = dp[i - 1][j - 1];
        if (word1[i - 1] != word2[j - 1])
          left_down += 1;
        dp[i][j] = std::min(left, std::min(down, left_down));
      }
    }
    return dp[word1.length()][word2.length()];
  }
};
// @lc code=end

/*
"zoologicoarchaeologist"\n"zoogeologist"
"pneumonoultramicroscopicsilicovolcanoconiosis"\n"ultramicroscopically"

*/