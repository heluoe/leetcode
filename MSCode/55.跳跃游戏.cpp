/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        bool ret = true;
        if (nums.empty() || nums.size() == 1)
            return true;

        int max_j = nums[0];
        int step = 0;
        while (step + max_j < nums.size() - 1)
        {
            int next_j = -1;
            int next_step = step;
            for (int i = step + 1; i <= step + max_j; ++i)
            {
                if (next_step + next_j < i + nums[i])
                {
                    next_j = nums[i];
                    next_step = i;
                }
            }
            if (next_step + next_j <= step + max_j)
                return false;
            step = next_step;
            max_j = next_j;
        }

        return ret;
    }
};
// @lc code=end

// [4,4,3,2,2,2,1,2]\n
