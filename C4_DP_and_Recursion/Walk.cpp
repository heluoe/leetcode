#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
class Solution
{

public:
    int walk(int N, int cur, int reset, int P)
    {
        int res = 0;
        if (reset == 0 && P != cur)
            return 0;

        if (P == cur && reset == 0)
            return 1;

        if (cur == 1)
        {
            return walk(N, cur + 1, reset - 1, P);
        }
        if (cur == N)
        {
            return walk(N, cur - 1, reset - 1, P);
        }

        res += walk(N, cur + 1, reset - 1, P);
        res += walk(N, cur - 1, reset - 1, P);
        return res;
    }
    int walk2(int N, int cur, int reset, int P)
    {
        std::vector<std::vector<int>> dp(reset + 1, std::vector<int>(N, 0));
        dp[0][P - 1] = 1;
        for (int i = 1; i <= reset; ++i)
        {
            dp[i][0] = dp[i - 1][1];
            for (int j = 1; j < N - 1; ++j)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
            dp[i][N - 1] = dp[i - 1][N - 2];
        }
        return dp[reset][cur - 1];
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    std::cout << sol.walk(5, 2, 3, 3) << std::endl;
    std::cout << sol.walk(3, 1, 3, 3) << std::endl;

    std::cout << "walk2: " << sol.walk2(5, 2, 3, 3) << std::endl;
    std::cout << "walk2: " << sol.walk2(3, 1, 3, 3) << std::endl;
    return 0;
}