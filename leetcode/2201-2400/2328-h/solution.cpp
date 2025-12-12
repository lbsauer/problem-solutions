// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid
// 2025/11/24

class Solution {
    constexpr static pair<int, int> dir[]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    constexpr static int MOD = 1'000'000'007;

    int dfs(const vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col) {
        if (dp[row][col] != 0) return dp[row][col];

        int count = 1;
        for (const auto [r, c] : dir) {
            if (
                row + r >= 0 && row + r < grid.size()    &&
                col + c >= 0 && col + c < grid[0].size() &&
                grid[row + r][col + c] < grid[row][col]
            ) {
                count = (count + dfs(grid, dp, row + r, col + c)) % MOD;
            }
        }

        return dp[row][col] = count;
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                count = (count + dfs(grid, dp, i, j)) % MOD;
            }
        }

        return count;
    }
};