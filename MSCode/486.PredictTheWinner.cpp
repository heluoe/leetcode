/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

// @lc code=start
class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        if (nums.size() < 2)
            return true;
        int n = nums.size() - 1;
        dp = vector<vector<int>>(nums.size(), vector<int>(nums.size(), INT_MIN));
        // return first_pick_scores(nums, 0, n) >= second_pick_scores(nums, 0, n);
        return scores(nums, 0, n) >= 0;
    }
    vector<vector<int>> dp;

    int scores(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return nums[l];

        if (dp[l][r] != INT_MIN)
            return dp[l][r];
        int val_left = nums[l] - scores(nums, l + 1, r);
        int val_right = nums[r] - scores(nums, l, r - 1);
        dp[l][r] = max(val_left, val_right);
        return dp[l][r];
    }

    int first_pick_scores(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return nums[l];

        return max(nums[l] + second_pick_scores(nums, l + 1, r), nums[r] + second_pick_scores(nums, l, r - 1));
    }

    int second_pick_scores(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return 0;

        return min(first_pick_scores(nums, l + 1, r), first_pick_scores(nums, l, r - 1));
    }
};
// @lc code=end
