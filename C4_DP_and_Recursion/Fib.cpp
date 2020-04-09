#include <iostream>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
// #509. Fibonacci Number
class Solution
{
public:
    //O(2^n)
    int fib0(int N)
    {
        if (N == 0)
            return 0;
        if (N == 1)
            return 1;

        return fib0(N - 1) + fib0(N - 2);
    }

    //O(n)
    int fib1(int N)
    {
        if (N == 0)
            return 0;
        if (N == 1 || N == 2)
            return 1;

        int res = 1;
        int pre = 1;
        int tmp = 0;
        for (int i = 3; i <= N; ++i)
        {
            tmp = res;
            res = res + pre;
            pre = tmp;
        }

        return res;
    }

    //O(logn)
    int fib2(int N)
    {
        if (N < 1)
            return 0;
        if (N == 1 || N == 2)
            return 1;
        vector<vector<int>> A({{1, 1}, {1, 0}});
        matrixPower(A, N - 2);
        return A[0][0] + A[0][1];
    }

    //Mutiple A = A^(N) with log(N) by using N's binary number
    // N = 5 = (101)b   A^5 = A^4 + A^1
    void matrixPower(vector<vector<int>> &A, int N)
    {
        vector<vector<int>> res(A.size(), vector<int>(A[0].size(), 0));
        for (int i = 0; i < A.size(); ++i)
            res[i][i] = 1;
        for (; N != 0; N >>= 1)
        {
            if (N & 1)
            {
                multiMatrix(res, A);
            }
            //caculate A, A*A, A^2 * A^2, A^4 * A^4 .... A^2n * A^2n
            multiMatrix(A, A);
        }
        for (int i = 0; i < res.size(); ++i)
            std::swap(A[i], res[i]);
    }

    //Matrix A *= B
    void multiMatrix(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> res(A.size());
        for (int i = 0; i < res.size(); ++i)
            res[i].resize(B[0].size(), 0);

        // rowA
        for (int i = 0; i < A.size(); ++i)
        {
            //colB
            for (int j = 0; j < B[0].size(); ++j)
            {
                //colA == rowB must!
                for (int k = 0; k < A[0].size(); ++k)
                    res[i][j] += A[i][k] * B[k][j];
            }
        }

        for (int i = 0; i < res.size(); ++i)
            std::swap(A[i], res[i]);
    }
};

int main(int argc, char **argv)
{
    std::random_device r;
    std::default_random_engine v1(r());
    std::uniform_int_distribution<int> uniform_k(0, 30);
    int N = static_cast<int>(std::round(uniform_k(v1)));
    Solution sol;
    std::cout << "Fib(" << N << ")" << std::endl;
    std::cout << "1. " << sol.fib0(N) << std::endl;
    std::cout << "2. " << sol.fib1(N) << std::endl;
    std::cout << "3. " << sol.fib2(N) << std::endl;
    return 0;
}