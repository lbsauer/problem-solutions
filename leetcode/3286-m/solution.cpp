// https://leetcode.com/problems/find-a-safe-walk-through-a-grid
// 2024-11-14

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        const int m = grid.size(), n = grid.front().size();
        
        vector<vector<int>> hp(m, vector<int>(n, -1));
        hp[0][0] = health - grid[0][0];

        deque<pair<int, int>> q{{0, 0}};

        while (!q.empty()) {
            const auto [x, y] = q.front();
            q.pop_front();

            const int w = hp[x][y];

            if (x + 1 < m && w - grid[x + 1][y] > hp[x + 1][y]) {
                hp[x + 1][y] = w - grid[x + 1][y];
                q.emplace_back(x + 1, y);
            }

            if (x > 0 && w - grid[x - 1][y] > hp[x - 1][y]) {
                hp[x - 1][y] = w - grid[x - 1][y];
                q.emplace_back(x - 1, y);
            }

            if (y + 1 < n && w - grid[x][y + 1] > hp[x][y + 1]) {
                hp[x][y + 1] = w - grid[x][y + 1];
                q.emplace_back(x, y + 1);
            }

            if (y > 0 && w - grid[x][y - 1] > hp[x][y - 1]) {
                hp[x][y - 1] = w - grid[x][y - 1];
                q.emplace_back(x, y - 1);
            }
        }

        return hp.back().back() > 0;
    }
};