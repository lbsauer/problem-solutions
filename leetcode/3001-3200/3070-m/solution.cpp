// https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k
// 2025/10/16

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int count = grid[0][0] <= k;

        for (int i = 1; i < grid.size(); ++i) {
            grid[i][0] += grid[i - 1][0];
            count += grid[i][0] <= k;
        }

        for (int i = 1; i < grid[0].size(); ++i) {
            grid[0][i] += grid[0][i - 1];
            count += grid[0][i] <= k;
        }

        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
                count += grid[i][j] <= k;
            }
        }

        return count;
    }
};