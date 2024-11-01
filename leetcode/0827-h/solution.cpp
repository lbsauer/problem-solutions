// https://leetcode.com/problems/making-a-large-island
// 2024/08/25

class Solution {
public:
    void fill(vector<vector<int>>& grid, const int i, const int j, int& count, const int color) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
            return;
        }

        ++count;
        grid[i][j] = color;

        fill(grid, i + 1, j, count, color);
        fill(grid, i - 1, j, count, color);
        fill(grid, i, j + 1, count, color);
        fill(grid, i, j - 1, count, color);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int color = 2;
        int largest = 0;

        vector<int> size{0, 0};

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 1) continue;

                int count = 0;
                fill(grid, i, j, count, color);

                largest = max(largest, count);
                size.push_back(count);
                ++color;
            }
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) continue;

                set<int> set{
                    i > 0 ? grid[i - 1][j] : 0,
                    j > 0 ? grid[i][j - 1] : 0,
                    i < grid.size() - 1 ? grid[i + 1][j] : 0,
                    j < grid[0].size() - 1 ? grid[i][j + 1] : 0
                };

                largest = max(
                    largest, 
                    accumulate(set.begin(), set.end(), 1, [&](const int sum, const int color) {
                        return sum + size[color];
                    }
                ));
            }
        }

        return largest;
    }
};