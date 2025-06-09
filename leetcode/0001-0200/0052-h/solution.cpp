// https://leetcode.com/problems/n-queens-ii
// 2025/03/18

class Solution {
    int solve(vector<string>& board, vector<bool>& mask, const int row, const int col, const int n) {
        if (row == n || mask[col] || mask[2 * n + row - col] || mask[3 * n + row + col]) return 0;

        board[row][col] = 'Q';
        mask[col] = mask[2 * n + row - col] = mask[3 * n + row + col] = true;

        int count = row == n - 1;
        for (int i = 0; i < n; ++i) {
            count += solve(board, mask, row + 1, i, n);
        }

        board[row][col] = '.';
        mask[col] = mask[2 * n + row - col] = mask[3 * n + row + col] = false;

        return count;
    }

public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> mask(5 * n);

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += solve(board, mask, 0, i, n);
        }

        return res;
    }
};