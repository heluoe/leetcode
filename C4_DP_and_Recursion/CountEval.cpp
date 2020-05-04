#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
    int countEval(string s, int result)
    {
        if (s.empty())
            return 0;

        vector<vector<int>> dp_t(s.length(), vector<int>(s.length(), 0)), dp_f(s.length(), vector<int>(s.length(), 0));
        dp_t[0][0] = s[0] == '1' ? 1 : 0;
        dp_f[0][0] = s[0] == '1' ? 0 : 1;
        for (int i = 2; i < s.length(); i += 2)
        {
            dp_t[i][i] = s[i] == '1' ? 1 : 0;
            dp_f[i][i] = s[i] == '1' ? 0 : 1;
            // left part
            for (int j = i - 2; j >= 0; j -= 2)
            {
                // right part
                for (int k = j; k < i; k += 2)
                {
                    if (s[k + 1] == '&')
                    {
                        dp_t[j][i] += dp_t[j][k] * dp_t[k + 2][i];
                        dp_f[j][i] += (dp_f[j][k] + dp_t[j][k]) * dp_f[k + 2][i] + dp_f[j][k] * dp_t[k + 2][i];
                    }
                    else if (s[k + 1] == '|')
                    {
                        dp_t[j][i] += (dp_f[j][k] + dp_t[j][k]) * dp_t[k + 2][i] + dp_t[j][k] * dp_f[k + 2][i];
                        dp_f[j][i] += dp_f[j][k] * dp_f[k + 2][i];
                    }
                    else
                    {
                        dp_t[j][i] += dp_f[j][k] * dp_t[k + 2][i] + dp_t[j][k] * dp_f[k + 2][i];
                        dp_f[j][i] += dp_f[j][k] * dp_f[k + 2][i] + dp_t[j][k] * dp_t[k + 2][i];
                    }
                }
            }
        }

        return result == 0 ? dp_f[0][s.length() - 1] : dp_t[0][s.length() - 1];
    }
};
