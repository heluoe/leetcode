/*
 * @lc app=leetcode.cn id=277 lang=cpp
 *
 * [277] Find the Celebrity
 */

// @lc code=start

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution
{
public:
    int findCelebrity(int n)
    {
        if (n == 0)
            return -1;
        if (n == 1)
            return 0;

        int c = 0;
        for (int i = 1; i < n; ++i)
        {
            if (knows(c, i))
                c = i;
        }

        for (int i = 0; i < n; ++i)
        {
            if (i == c)
                continue;
            if (knows(c, i) || !knows(i, c))
                return -1;
        }

        return c;
    }
};
// @lc code=end
