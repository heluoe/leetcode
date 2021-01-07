#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix.size() == 1)
            return;
        int edge = matrix.size();

        int l = 0, m = 0;
        while (edge - l > 1)
        {
            int cx = m + (edge - l) - 1;

            swap(matrix[m][cx], matrix[m][m]);
            swap(matrix[m][m], matrix[cx][m]);
            swap(matrix[cx][m], matrix[cx][cx]);

            for (int idx = cx - 1, dc = 1; idx > m; --idx, ++dc)
            {
                swap(matrix[m][cx - dc], matrix[m + dc][m]);
                swap(matrix[m + dc][m], matrix[cx][m + dc]);
                swap(matrix[cx][m + dc], matrix[cx - dc][cx]);
            }
            m++;
            l += 2;
        }
    }
};
// @lc code=end

int main(int argc, char **argv)
{

    Solution sol;
    //vector<int> nums1 = {1, 2}, nums2 = {3, 4};
    //vector<vector<int>> nums{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //[   [ 5, 1, 9,11],   [ 2, 4, 8,10],   [13, 3, 6, 7],   [15,14,12,16] ]
    vector<vector<int>> nums{
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    sol.rotate(nums);

    return 0;
}