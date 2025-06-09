// https://leetcode.com/problems/sort-matrix-by-diagonals
// 2025/03/18

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<int> nums(grid.size());

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size() - i; ++j) {
                nums[j] = grid[i + j][j];
            }

            sort(nums.begin(), prev(nums.end(), i), greater<int>{});

            for (int j = 0; j < grid.size() - i; ++j) {
                grid[i + j][j] = nums[j];
            }
        }

        for (int j = 1; j < grid.size(); ++j) {
            for (int i = 0; i < grid.size() - j; ++i) {
                nums[i] = grid[i][j + i];
            }

            sort(nums.begin(), prev(nums.end(), j));

            for (int i = 0; i < grid.size() - j; ++i) {
                grid[i][j + i] = nums[i];
            }
        }

        return grid;
    }
};