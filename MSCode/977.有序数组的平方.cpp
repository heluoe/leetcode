/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if(A.empty())
            return A;
        
        int p = 0, l = 0, r = 0;
        while(l < A.size())
        {
            if(A[l] < 0)
                p++;
            
            A[l] = A[l]*A[l];

            l++;
        }
        if(p == 0 || p == A.size())
            return A;

        vector<int> res;
        l = p - 1; r = p;
        while(res.size() != A.size())
        {
           
            if(r == A.size() || (l >= 0 && A[l] < A[r]))
            {
                res.push_back(A[l]);
                l--;
            }
            else if(l < 0 || (r < A.size() && A[l] >= A[r] ) )
            {
                res.push_back(A[r]);
                r++;
            }
            


        }
        return res;
    }
};
// @lc code=end

// [-4,-1,0,3,10]
