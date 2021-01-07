#include <vector>
#include <limits> // std::numeric_limits
#include <iostream>
using namespace std;

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        ///
        /// #0#.#.#.#.#.#.#c1#.#.#   (N1 - 1), N1 = 2*n1+1, n1=nums1.size
        /// #0#.#.#.#c2#.#.#.#.#.#.# (N2 - 1), N2 = 2*n2+1, n2=nums2.size, n1 < n2
        /// constrain of left_size = right_size
        /// c1 + c2  =  (N1 - 1 - c1) + (N2 - 1 - c2)
        /// c1 set, then c2 = n1+n2 - c1

        /// find c1 in 0...N1-1 (2*n1) binary search satisfy (c1 <- (bin_low = 0 + bin_up = 2*n1)/2 )
        /// Get
        /// L1 = nums[(c1 - 1)/ 2], R1 = nums[c1/2], L1 < R1
        /// L2 = nums[(c2 - 1)/2], R2 = nums[c2/2], L2 < R2
        /// L1 < R2 && R1 > L2
        ///     then median = (max(L1, L2) + min(R1, R2) ) / 2
        /// if L1 > R2 find c1 in [bin_low = bin_low, bin_up = c1--] / 2
        /// if R1 < L2 find c1 in [bin_low = c1++, bin_up=bin_up] / 2
        double median = 0.0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int bin_low = 0, bin_up = 2 * n1;

        // int L1, L2, R1, R2;
        while (bin_low <= bin_up)
        {
            const int c1 = (bin_low + bin_up) / 2;
            const int c2 = n1 + n2 - c1;
            const int L1 = (c1 == 0) ? numeric_limits<int>::min() : nums1[(c1 - 1) / 2];
            const int R1 = (c1 == 2 * n1) ? numeric_limits<int>::max() : nums1[c1 / 2];

            const int L2 = (c2 == 0) ? numeric_limits<int>::min() : nums2[(c2 - 1) / 2];
            const int R2 = (c2 == 2 * n2) ? numeric_limits<int>::max() : nums2[c2 / 2];
            if (L1 > R2)
            {
                bin_up = c1 - 1;
            }
            else if (R1 < L2)
            {
                bin_low = c1 + 1;
            }
            else
            {
                median = (max(L1, L2) + min(R1, R2)) / 2.0;
                break;
            }
        }
        return median;
    }
    double findMedianSortedArraysBad(vector<int> &nums1, vector<int> &nums2)
    {
        /// media_index = k1, k2
        /// num1[0:k1].size + num2[0:k2].size == num1[k1+1:].size + num2[k2+1:].size
        /// max(num1[0:k1],num2[0:k2]) <= min(num1[k1+1:],num2[k2+1:])
        /// media = (max(num1[0:k1],num2[0:k2])+min(num1[k1+1:],num2[k2+1:])) / 2

        /// # 1 # 2 # 3 # 4 # ==> k1 --> 2*n1+1
        /// # 1 # 2 #  ==> k2 --> 2*n2+1
        int ext1 = 2 * nums1.size() + 1, ext2 = 2 * nums2.size() + 1;
        for (int k1 = 0; k1 < ext1; ++k1)
        {
            for (int k2 = 0; k2 < ext2; ++k2)
            {
                if ((k1 == 0 && k2 == 0) || (k1 == ext1 && k2 == ext2))
                {
                    continue;
                }
                int left_size, right_size, l1 = k1 / 2, r1, l2 = k2 / 2, r2;
                r1 = k1 % 2 == 0 ? nums1.size() - l1 : nums1.size() - l1 - 1;
                r2 = k2 % 2 == 0 ? nums2.size() - l2 : nums2.size() - l2 - 1;
                left_size = l1 + l2;
                right_size = r1 + r2;
                if (left_size != right_size)
                {
                    continue;
                }
                int l1_m = k1 % 2 != 0 ? nums1[k1 / 2] : (k1 == 0 ? numeric_limits<int>::min() : nums1[(k1 - 1) / 2]);
                int l2_m = k2 % 2 != 0 ? nums2[k2 / 2] : (k2 == 0 ? numeric_limits<int>::min() : nums2[(k2 - 1) / 2]);
                double ml = static_cast<double>(std::max(l1_m, l2_m));

                int r1_m = k1 % 2 != 0 ? nums1[k1 / 2] : (k1 == ext1 - 1 ? numeric_limits<int>::max() : nums1[(k1 + 1) / 2]);
                int r2_m = k2 % 2 != 0 ? nums2[k2 / 2] : (k2 == ext2 - 1 ? numeric_limits<int>::max() : nums2[(k2 + 1) / 2]);
                double mr = static_cast<double>(std::min(r1_m, r2_m));

                if (ml > mr)
                {
                    continue;
                }

                return (ml + mr) / 2.0;
            }
        }
        return 0.0;
    }
};
// @lc code=end

int main(int argc, char **argv)
{

    Solution sol;
    //vector<int> nums1 = {1, 2}, nums2 = {3, 4};
    vector<int> nums1 = {3}, nums2 = {-2, -1};
    std::cout << sol.findMedianSortedArrays(nums1, nums2) << std::endl;

    return 0;
}