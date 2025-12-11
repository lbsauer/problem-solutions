// https://leetcode.com/problems/battleships-in-a-board
// 2025/08/01

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = board[0][0] == 'X';

        for (int i = 1; i < board.size(); ++i) {
            count += board[i][0] == 'X' && board[i - 1][0] != 'X';
        }

        for (int i = 1; i < board[0].size(); ++i) {
            count += board[0][i] == 'X' && board[0][i - 1] != 'X';
        }

        for (int i = 1; i < board.size(); ++i) {
            for (int j = 1; j < board[0].size(); ++j) {
                count += board[i][j] == 'X' && board[i - 1][j] != 'X' && board[i][j - 1] != 'X';
            }
        }

        return count;
    }
};