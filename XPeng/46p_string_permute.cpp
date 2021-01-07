#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
  public:
    vector<vector<int>> permute(string& values)
    {
        vector<int> nums;
        for (int i = 0; i < values.length(); ++i)
        {
            nums.push_back(i);
        }

        vector<vector<int>> result;
        const int len = nums.size();
        if (nums.empty())
            return result;

        // c[i] is the number of elements lying to the
        // right of the i-th smallest element of set[]
        // notice : i >= 0 && i < n
        vector<int> c(len, 0);
        // o[i] governs the direction by which c[i] changes
        vector<int> o(len, 1);
        // Get origin nums[1..len]
        // 1. j = len, s = 0
        // 2. q = c[j] + o[j]
        // 3. if q < 0 || q >= j + 1 Goto 7.
        // 4. exchange(nums[j - c[j] + s], nums[j - q +s])
        // 5. Get exchanged nums[1..len]
        // 6. c[j] = q, j = len -1, s = 0, GoTO 2.
        // 7. if q != j + 1  GoTo 10.
        // 8. j == 0 Done.
        // 9. s++
        // 10. o[j] = -o[j], j--, Goto 2.
        int j = len - 1, s = 0;
        result.push_back(nums);
        while (true)
        {
            int q = c[j] + o[j];
            if (q >= 0 && q < j + 1)
            {
                swap(nums[j - c[j] + s], nums[j - q + s]);
                result.push_back(nums);
                c[j] = q;
                j = len - 1;
                s = 0;
                continue;
            }
            if (q == j + 1)
            {
                if (j == 0)
                {
                    break;
                }
                s++;
            }
            o[j] = -o[j];
            j--;
        }

        return result;
    }
};
// @lc code=end

int main(int argc, char** argv)
{

    Solution sol;
    // vector<int> nums1 = {1, 2}, nums2 = {3, 4};
    string values = "abcdefcs";
    const auto& result = sol.permute(values);

    set<string> str_result;
    for (const auto& index : result)
    {
        string strs;
        for (const auto i : index)
        {
            strs.push_back(values[i]);
        }
        str_result.insert(strs);
    }
    for (const auto strs : str_result)
    {
        std::cout << strs << std::endl;
    }
    return 0;
}