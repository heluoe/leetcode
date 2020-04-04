#include <iostream>
#include <stack>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
int maxRecSizeFromBottom(const std::vector<int> &arr);

int largestRectangleArea(std::vector<int> &height)
{
    int res = 0;
    std::stack<int> s;
    height.push_back(-1);
    for (int i = 0; i < height.size(); ++i)
    {
        if (s.empty() || height[s.top()] <= height[i])
            s.push(i);
        else
        {
            int tmp = s.top();
            s.pop();
            res = std::max(res, height[tmp] * (s.empty() ? i : (i - s.top() - 1)));
            --i;
        }
    }
    return res;
}

int maxRecSize(std::vector<std::vector<char>> &matrix)
{
    std::vector<int> height(matrix[0].size(), 0);
    int maxArea = 0;
    for (const auto &row : matrix)
    {
        for (size_t idx = 0; idx < row.size(); ++idx)
        {
            height[idx] = row[idx] == '0' ? 0 : height[idx] + 1;
        }
        maxArea = std::max(maxArea, largestRectangleArea(height));
    }
    return maxArea;
}

int maxRecSizeFromBottom(const std::vector<int> &arr)
{
    std::vector<std::pair<int, int>> ans(arr.size(), {-1, -1});
    std::stack<std::vector<int>> stackBuf;
    int maxArea = 0;
    for (int idx = 0; idx < arr.size(); ++idx)
    {

        std::vector<int> itr_top;
        while (!stackBuf.empty() && arr[idx] < arr[stackBuf.top().back()])
        {
            itr_top = stackBuf.top();
            stackBuf.pop();
            for (auto itr_idx : itr_top)
                ans[itr_idx].second = idx;

            for (auto idx_r : itr_top)
            {
                ans[idx_r].first = stackBuf.empty() ? -1 : stackBuf.top().back();
                auto idx_l = stackBuf.empty() ? 0 : stackBuf.top().back() + 1;
                maxArea = std::max(maxArea, static_cast<int>(idx_r - idx_l + 1) * arr[idx_r]);
            }
        }
        if (stackBuf.empty() || arr[idx] > arr[stackBuf.top().front()])
        {
            stackBuf.push(std::vector<int>({idx}));
        }
        else //arr[idx] == arr[stackBuf.top().front()]
        {
            stackBuf.top().push_back(idx);
        }
    }
    // std::cout << std::endl;
    while (stackBuf.size() > 0)
    {
        auto itr_top = stackBuf.top();
        stackBuf.pop();

        if (stackBuf.size() == 0)
        {
            for (auto itr_idx : itr_top)
            {
                auto idx_r = ans[itr_idx].second == -1 ? (arr.size() - 1) : (ans[itr_idx].second - 1);
                auto idx_l = ans[itr_idx].first == -1 ? 0 : ans[itr_idx].first + 1;
                maxArea = std::max(maxArea, static_cast<int>(idx_r - idx_l + 1) * arr[itr_idx]);
            }
            break;
        }

        for (auto itr_idx : itr_top)
        {
            auto idx_l = ans[itr_idx].first = stackBuf.top().back() + 1;
            auto idx_r = ans[itr_idx].second == -1 ? (arr.size() - 1) : (ans[itr_idx].second - 1);
            maxArea = std::max(maxArea, static_cast<int>(idx_r - idx_l + 1) * arr[itr_idx]);
        }
    }
    return maxArea;
}

int maximalRectangle(std::vector<std::vector<char>> &matrix)
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = matrix.size();
    if (!n)
    {
        return 0;
    }
    int m = matrix[0].size();
    vector<int> height(m + 1, 0);
    vector<int> left(m + 1, 0);
    vector<int> right(m + 1, m - 1);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int cur_left = 0;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                height[j]++;
                left[j] = max(left[j], cur_left);
            }
            else
            {
                height[j] = 0;
                left[j] = 0;
                cur_left = j + 1;
            }
        }
        int cur_right = m - 1;
        for (int j = m - 1; j > -1; j--)
        {
            if (matrix[i][j] == '1')
            {
                right[j] = min(right[j], cur_right);
                result = max(result, height[j] * (right[j] - left[j] + 1));
            }
            else
            {
                right[j] = m - 1;
                cur_right = j - 1;
            }
        }
    }
    return result;
}

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::default_random_engine v2(r());
    std::uniform_int_distribution<int> uniform_dist(1, 35);
    std::uniform_int_distribution<int> uniform_bool(0, 17);

    auto rows = static_cast<int>(std::round(uniform_dist(v1)));
    auto cols = static_cast<int>(std::round(uniform_dist(v1)));
    std::vector<std::vector<char>> matrix_data(
        {{'0', '1', '1', '0', '1'}, {'1', '1', '0', '1', '0'}, {'0', '1', '1', '1', '0'}, {'1', '1', '1', '1', '0'}, {'1', '1', '1', '1', '1'}, {'0', '0', '0', '0', '0'}});
    // std::vector<std::vector<char>> matrix_data(rows);
    // std::cout
    //     << "Matrix: = " << std::endl;
    // for (int row = 0; row < rows; ++row)
    // {
    //     std::cout << "          ";
    //     for (int col = 0; col < cols; ++col)
    //     {
    //         char val;
    //         if (static_cast<int>(std::round(uniform_bool(v2))) > 1)
    //             val = '1';
    //         else
    //             val = '0';
    //         matrix_data[row].push_back(val);
    //         std::cout << matrix_data[row].back() << " ";
    //     }
    //     std::cout << std::endl;
    // }
    auto ret = maxRecSize(matrix_data);
    std::cout << "MaxSubNonArea = " << ret << std::endl;
    //std::cout << maxRecSizeFromBottom({2, 0, 0, 7, 1, 0, 4, 0, 0}) << std::endl;
    return 0;
}