/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int n = prices.size();
        vector<int> dp_buy(n), dp_sell(n);
        dp_buy[0] = prices[0];
        dp_sell[n - 1] = prices[n - 1];
        for (int i = 1; i < n; ++i)
        {
            dp_buy[i] = min(prices[i], dp_buy[i - 1]);
            dp_sell[n - 1 - i] = max(prices[n - 1 - i], dp_sell[n - i]);
        }
        int best = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            int earn = dp_sell[i + 1] - dp_buy[i];
            if (earn > 0 && best < earn)
            {
                best = earn;
            }
        }
        return best;
    }
};
// @lc code=end
