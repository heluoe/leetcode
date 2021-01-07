/*
 * @lc app=leetcode.cn id=348 lang=cpp
 *
 * [348] Design Tic-Tac-Toe
 */

// @lc code=start
class TicTacToe
{
public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
    {
        prow = vector<vector<int>>(2, vector<int>(n, n));
        pcol = vector<vector<int>>(2, vector<int>(n, n));
        pdiag = vector<vector<int>>(2, vector<int>(2, n));
        n_ = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player)
    {

        prow[player - 1][row]--;
        pcol[player - 1][col]--;
        if (row == col)
            pdiag[player - 1][0]--;
        if (row + col == n_ - 1)
            pdiag[player - 1][1]--;

        if (prow[player - 1][row] == 0 || pcol[player - 1][col] == 0 || pdiag[player - 1][0] == 0 || pdiag[player - 1][1] == 0)
            return player;
        return 0;
    }
    int n_;
    vector<vector<int>> prow, pcol, pdiag;
};
// @lc code=end

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */