// https://leetcode.com/problems/n-queens
// 2025/03/17

class Solution {
    void solve(vector<vector<string>>& res, vector<string>& board, vector<bool>& mask, int row, int col, int n) {
        if (mask[col] || mask[2 * n + row - col] || mask[3 * n + row + col]) return;

        board[row][col] = 'Q';
        mask[col] = mask[2 * n + row - col] = mask[3 * n + row + col] = true;

        if (row == n - 1) {
            res.push_back(board);
        } else {
            for (int i = 0; i < n; ++i) {
                solve(res, board, mask, row + 1, i, n);
            }
        }

        board[row][col] = '.';
        mask[col] = mask[2 * n + row - col] = mask[3 * n + row + col] = false;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> mask(5 * n);

        vector<vector<string>> res;
        for (int i = 0; i < n; ++i) {
            solve(res, board, mask, 0, i, n);
        }

        return res;
    }
};