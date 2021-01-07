/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> results;
        int i = 0, j = 0;
        while (i < m || j < n)
        {
            if (i < m && j < n)
            {
                if (nums1[i] < nums2[j])
                {
                    results.push_back(nums1[i]);
                    i++;
                    continue;
                }
                else
                {
                    results.push_back(nums2[j]);
                    j++;
                    continue;
                }
            }
            if (i < m)
            {
                results.push_back(nums1[i]);
                i++;
            }
            if (j < n)
            {
                results.push_back(nums2[j]);
                j++;
            }
        }
        swap(nums1, results);
    }
};
// @lc code=end
