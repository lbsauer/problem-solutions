// https://leetcode.com/problems/magic-squares-in-grid
// 2024/08/08

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3) return 0;
        
        int count = 0;

        for (uint8_t i = 0; i < grid.size() - 2; ++i) {
            for (uint8_t j = 0; j < grid[0].size() - 2; ++j) {
                uint16_t check = 0;
                check |= (1 << grid[i][j]);
                check |= (1 << grid[i][j + 1]);
                check |= (1 << grid[i][j + 2]);
                check |= (1 << grid[i + 1][j]);
                check |= (1 << grid[i + 1][j + 1]);
                check |= (1 << grid[i + 1][j + 2]);
                check |= (1 << grid[i + 2][j]);
                check |= (1 << grid[i + 2][j + 1]);
                check |= (1 << grid[i + 2][j + 2]);

                if (check != 0b1111111110) continue;

                uint8_t sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];

                if ((grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2]) != sum ||
                    (grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2]) != sum ||
                    (grid[i][j]     + grid[i + 1][j]     + grid[i + 2][j])     != sum ||
                    (grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1]) != sum ||
                    (grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2]) != sum ||
                    (grid[i][j]     + grid[i + 1][j + 1] + grid[i + 2][j + 2]) != sum ||
                    (grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2])     != sum) {
                    continue;
                }

                ++count;
            }
        }

        return count;
    }
};