#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

class Solution {
public:
  int do_map_coins(int rest, int it, vector<int> &coins) {
    int count = 0;
    if (it == coins.size())
      count = rest == 0 ? 1 : 0;
    else {
      for (int i = 0; i * coins[it] <= rest; ++i) {
        auto map_val = map[rest - i * coins[it]][it + 1];
        count = map_val == -1
                    ? count + do_map_coins(rest - i * coins[it], it + 1, coins)
                    : count + map_val;
      }
    }

    map[rest][it] = count;
    return count;
  }
  int change4(int amount, vector<int> &coins) {
    int size = coins.size();
    if (size == 0 && amount == 0)
      return 1;
    if (size == 0)
      return 0;

    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins)
      for (int i = coin; i <= amount; i++)
        dp[i] += dp[i - coin];

    return dp[amount];
  }
  int change3(int amount, vector<int> &coins) {
    if (amount == 0)
      return 1;
    if (amount > 0 && coins.empty())
      return 0;
    int N = coins.size();
    vector<vector<int>> dp(N, vector<int>(amount + 1, 0));
    for (int i = 0; i * coins[0] <= amount; ++i)
      dp[0][i * coins[0]] = 1;
    for (int i = 1; i < N; ++i)
      dp[i][0] = 1;
    for (int i = 1; i < N; ++i) {
      for (int j = 1; j <= amount; ++j) {
        dp[i][j] = dp[i - 1][j];
        dp[i][j] += (j - coins[i] >= 0 ? dp[i][j - coins[i]] : 0);
      }
    }
    return dp[N - 1][amount];
  }

  int change2(int amount, vector<int> &coins) {
    if (amount == 0)
      return 1;
    if (amount > 0 && coins.empty())
      return 0;
    int N = coins.size();
    vector<vector<int>> dp(N, vector<int>(amount + 1, 0));
    for (int i = 0; i * coins[0] <= amount; ++i)
      dp[0][i * coins[0]] = 1;
    for (int i = 1; i < N; ++i)
      dp[i][0] = 1;
    for (int i = 1; i < N; ++i) {
      for (int j = 1; j <= amount; ++j) {
        int num = 0;
        for (int k = 0; j - k * coins[i] >= 0; ++k)
          num += dp[i - 1][j - k * coins[i]];

        dp[i][j] = num;
      }
    }
    return dp[N - 1][amount];
  }
  int change(int amount, vector<int> &coins) {
    if (amount == 0)
      return 1;
    if (amount > 0 && coins.empty())
      return 0;

    map.resize(amount + 1, vector<int>(coins.size() + 1, -1));
    return do_map_coins(amount, 0, coins);
  }
  int do_coins(int rest, int it, vector<int> &coins) {
    int count = 0;
    if (it == coins.size() && rest != 0)
      return 0;
    if (rest == 0)
      return 1;
    for (int i = 0; i * coins[it] <= rest; ++i) {
      count += do_coins(rest - i * coins[it], it + 1, coins);
    }
    return count;
  }

private:
  vector<vector<int>> map;
};

int main(int argc, char **argv) {
  Solution sol;
  std::vector<int> c({1, 2, 5});
  std::cout << sol.do_coins(5, 0, c) << std::endl;
  std::cout << sol.change(5, c) << std::endl;
  return 0;
}