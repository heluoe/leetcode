/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.empty() || nums.size() == 1)
            return 0;

        vector<int> states(2, 0); // {current jump, next jump }

        int jumps = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (states[0] < i)
            {
                jumps++;
                states[0] = states[1];
            }
            states[1] = max(states[1], nums[i] + i);
        }

        return jumps;
    }
};
// @lc code=end
