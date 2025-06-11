// https://leetcode.com/problems/path-with-maximum-gold
// 2025/05/18

class Solution {
    constexpr static pair<int, int> directions[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    void dfs(vector<vector<int>>& grid, int row, int col, int gold, int& max_gold) {
        if (grid[row][col] <= 0) return;

        gold += grid[row][col];
        max_gold = max(max_gold, gold);

        grid[row][col] = -grid[row][col];

        for (const auto [dr, dc] : directions) {
            if (row + dr < 0 || row + dr >= grid.size() || col + dc < 0 || col + dc >= grid[0].size()) continue;

            dfs(grid, row + dr, col + dc, gold, max_gold);
        }

        grid[row][col] = -grid[row][col];
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int count_zero = 0, sum = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                sum += grid[i][j];
                count_zero += grid[i][j] == 0;
            }
        }

        if (count_zero == 0) return sum;

        int max_gold = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) dfs(grid, i, j, 0, max_gold);
            }
        }

        return max_gold;
    }
};