#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxCoins_slow(vector<int> &nums)
    {
        std::vector<int> arr(nums.size() + 2, 1);
        for (int i = 0; i < nums.size(); ++i)
            arr[i + 1] = nums[i];
        return doprocess(arr, 1, nums.size());
    }

    int maxCoins(vector<int> &nums)
    {
        int N = nums.size();
        if (N < 1)
            return 0;
        if (N == 1)
            return nums[0];

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        std::vector<std::vector<int>> dp(N + 2, std::vector<int>(N + 2, 0));
        //case 1. just rest 1 balloon L ==R
        for (int i = 1; i <= N; ++i)
            dp[i][i] = nums[i - 1] * nums[i] * nums[i + 1];
        for (int L = N; L >= 1; --L)
        {
            for (int R = L + 1; R <= N; ++R)
            {
                // case 2. hit [L] at last before [L +1] to [R] done, then max += [L-1] * [L] * [R +1]
                int max_L = nums[L - 1] * nums[L] * nums[R + 1] + dp[L + 1][R];
                // case 3. hit [R] at last before [L] to [R -1] done, then max += [L-1] * [R] * [R+1]
                int max_R = nums[L - 1] * nums[R] * nums[R + 1] + dp[L][R - 1];
                dp[L][R] = std::max(max_L, max_R);
                // case 4. hit every [i] at last ... then,
                for (int i = L + 1; i < R; ++i)
                {
                    dp[L][R] = std::max(dp[L][R], dp[L][i - 1] + nums[L - 1] * nums[i] * nums[R + 1] + dp[i + 1][R]);
                }
            }
        }
        return dp[1][N];
    }

    // 0... ...[L-1] [L] [L +1] ...[i]...[R-1] [R] [R+1]... ...N
    // just caculate [L] [R]
    int doprocess(vector<int> &nums, int L, int R)
    {
        //case 1. just rest 1 balloon L ==R
        if (L == R)
            return nums[L - 1] * nums[L] * nums[R + 1];

        // case 2. hit [L] at last before [L +1] to [R] done, then max += [L-1] * [L] * [R +1]
        int max = nums[L - 1] * nums[L] * nums[R + 1] + doprocess(nums, L + 1, R);
        // case 3. hit [R] at last before [L] to [R -1] done, then max += [L-1] * [R] * [R+1]
        max = std::max(max, nums[L - 1] * nums[R] * nums[R + 1] + doprocess(nums, L, R - 1));
        // case 4. hit every [i] at last ... then,
        for (int i = L + 1; i < R; ++i)
            max = std::max(max, doprocess(nums, L, i - 1) + nums[L - 1] * nums[i] * nums[R + 1] + doprocess(nums, i + 1, R));

        return max;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    std::vector<int> c({1, 2, 5});
    std::cout << sol.maxCoins(c) << std::endl;
    return 0;
}