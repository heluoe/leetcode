#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map_nums;
        std::vector<int> ret;
        for (auto i = 0; i < nums.size(); ++i)
        {
            const auto num = nums[i];
            if (map_nums.find(num) == map_nums.end())
            {
                map_nums[num] = i;
            }
            if (map_nums.find(target - num) != map_nums.end() && map_nums[target - num] != i)
            {
                ret.push_back(i);
                ret.push_back(map_nums[target - num]);
                break;
            }
        }
        return ret;
    }
};
// @lc code=end

int main(int argc, char **argv)
{

    Solution sol;
    vector<int> test_nums = {3, 2, 4};
    sol.twoSum(test_nums, 6);

    return 0;
}