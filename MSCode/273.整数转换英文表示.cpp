/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
class Solution
{
public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        vector<int> step = {1000000000, 1000000, 1000, 100, 10, 1};
        create_nums_map();
        string res = "";
        for (int i = 0; i < 3; ++i)
        {
            int num1 = num / step[i];
            num = num % step[i];

            if (num1 > 0)
            {
                if (!res.empty())
                    res += " ";
                res = res + to_hundred(num1) + " " + nums_map[step[i]];
            }
        }
        string res1 = to_hundred(num);
        if (!res.empty() && !res1.empty())
            res = res + " " + res1;
        else if (res.empty() && !res1.empty())
            return res1;

        return res;
    }

    string to_hundred(int num)
    {
        string res = "";
        int num1 = num / 100;
        if (num1 > 0)
        {
            res = nums_map[num1] + " " + nums_map[100];
            num = num % 100;
        }

        if (nums_map.find(num) != nums_map.end())
        {
            if (!res.empty())
                res += " ";
            res = res + nums_map[num];
            return res;
        }
        num1 = num / 10;
        if (num1 > 0)
        {
            if (!res.empty())
                res += " ";
            res = res + nums_map[num1 * 10];
            num = num % 10;
        }

        if (num > 0)
        {
            if (!res.empty())
                res += " ";
            res = res + nums_map[num];
        }
        return res;
    }
    void create_nums_map()
    {
        nums_map[1] = "One";
        nums_map[2] = "Two";
        nums_map[3] = "Three";
        nums_map[4] = "Four";
        nums_map[5] = "Five";
        nums_map[6] = "Six";
        nums_map[7] = "Seven";
        nums_map[8] = "Eight";
        nums_map[9] = "Nine";
        nums_map[10] = "Ten";
        nums_map[11] = "Eleven";
        nums_map[12] = "Twelve";
        nums_map[13] = "Thirteen";
        nums_map[14] = "Fourteen";
        nums_map[15] = "Fifteen";
        nums_map[16] = "Sixteen";
        nums_map[17] = "Seventeen";
        nums_map[18] = "Eighteen";
        nums_map[19] = "Nineteen";
        nums_map[20] = "Twenty";
        nums_map[30] = "Thirty";
        nums_map[40] = "Forty";
        nums_map[50] = "Fifty";
        nums_map[60] = "Sixty";
        nums_map[70] = "Seventy";
        nums_map[80] = "Eighty";
        nums_map[90] = "Ninety";
        nums_map[100] = "Hundred";
        nums_map[1000] = "Thousand";
        nums_map[1000000] = "Million";
        nums_map[1000000000] = "Billion";
    }

    unordered_map<int, string> nums_map;
};
// @lc code=end
// 100