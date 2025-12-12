// https://leetcode.com/problems/number-of-closed-islands
// 2025/12/08

class Solution {
    constexpr static pair<int, int> directions[]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool dfs(vector<vector<int>>& grid, int row, int col, int m, int n) {
        if (grid[row][col] != 0) return false;

        grid[row][col] = 2;

        bool check = row == 0 || col == 0 || row == m - 1 || col == n - 1;
        for (const auto [dr, dc] : directions) {
            if (row + dr >= 0 && row + dr < m && col + dc >= 0 && col + dc < n) {
                check = dfs(grid, row + dr, col + dc, m, n) || check;
            }
        }

        return check;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                count += grid[i][j] == 0 && !dfs(grid, i, j, m, n);
            }
        }

        return count;
    }
};