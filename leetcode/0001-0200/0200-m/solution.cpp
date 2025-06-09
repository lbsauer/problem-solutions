// https://leetcode.com/problems/number-of-islands
// 2024/03/30

class Solution {
public:
    void flood_fill(std::vector<std::vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= grid[0].size()) return;
        if (y < 0 || y >= grid.size()) return;
        if (grid[y][x] == '0') return;

        grid[y][x] = '0';

        flood_fill(grid, x, y + 1);
        flood_fill(grid, x, y - 1);
        flood_fill(grid, x + 1, y);
        flood_fill(grid, x - 1, y);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
    
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '0') continue;
                
                ++count;
                flood_fill(grid, j, i);
            }
        }

        return count;
    }
};