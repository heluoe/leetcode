#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (coins.empty() || amount < 1)
            return 0;
        return process(coins, 0, amount);
    }

    int process(vector<int> &coins, int i, int rest)
    {
        if (i == coins.size())
            return rest == 0 ? 0 : -1;
        int ret = -1;
        for (int it = 0; it * coins[i] <= rest; ++it)
        {
            auto next_ret = process(coins, i + 1, rest - it * coins[i]);
            if (next_ret != -1)
                ret = ret == -1 ? next_ret + it : std::min(ret, next_ret + it);
        }
        return ret;
    }

    int coinChange3(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, std::numeric_limits<int>::max());
        dp[0] = 0;
        int n = coins.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if (dp[j] - 1 > dp[j - coins[i]])
                {
                    dp[j] = 1 + dp[j - coins[i]];
                }
            }
        }
        return dp[amount] == std::numeric_limits<int>::max() ? -1 : dp[amount];
    }

    int coinChange2(vector<int> &coins, int amount)
    {
        if (coins.empty() || amount < 1)
            return 0;
        int N = coins.size();
        vector<vector<int>> dp(N + 1, vector<int>(amount + 1, -1));
        dp[N][0] = 0;
        for (int i = N - 1; i >= 0; --i)
        {
            for (int rest = 0; rest <= amount; ++rest)
            {
                if (dp[i + 1][rest] != -1)
                    dp[i][rest] = dp[i + 1][rest];
                if (rest - coins[i] >= 0 && dp[i][rest - coins[i]] != -1)
                {
                    if (dp[i + 1][rest] == -1)
                        dp[i][rest] = dp[i][rest - coins[i]] + 1;
                    else
                    {
                        dp[i][rest] = std::min(dp[i + 1][rest], dp[i][rest - coins[i]] + 1);
                    }
                }
            }
        }
        return dp[0][amount];
    }
};

int main(int argc, char **argv)
{
    std::vector<int> coins({2, 3, 5, 1});
    Solution sol;
    std::cout << sol.coinChange2(coins, 120) << std::endl;
    return 0;
}