// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid
// 2025/05/08

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid.front().size();

        vector<bool> curr(m), prev(m, true);

        int max_moves = 0;
        for (int col = 1; col < n; ++col) {
            for (int row = 0; row < m; ++row) {
                for (int d = -1; d <= 1 && !curr[row]; ++d) {
                    if (row + d < 0 || row + d >= m) continue;

                    curr[row] = grid[row][col] > grid[row + d][col - 1] && prev[row + d];
                }
            }

            if (all_of(curr.begin(), curr.end(), logical_not{})) break;

            curr.swap(prev);
            curr.assign(m, false);

            ++max_moves;
        }

        return max_moves;
    }
};