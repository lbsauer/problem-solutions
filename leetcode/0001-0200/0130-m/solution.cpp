// https://leetcode.com/problems/surrounded-regions
// 2025/12/07

class Solution {
    constexpr static pair<int, int> directions[]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs(vector<vector<char>>& board, int row, int col, char from, char to) {
        if (board[row][col] != from) return;

        board[row][col] = to;

        for (auto [r, c] : directions) {
            r += row;
            c += col;

            if (r >= 0 && r < board.size() && c >= 0 && c < board[r].size()) {
                dfs(board, r, c, from, to);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            dfs(board, i, 0, 'O', ' ');
            dfs(board, i, board[0].size() - 1, 'O', ' ');
        }

        for (int i = 1; i < board[0].size() - 1; ++i) {
            dfs(board, 0, i, 'O', ' ');
            dfs(board, board.size() - 1, i, 'O', ' ');
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};