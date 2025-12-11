// https://leetcode.com/problems/find-the-width-of-columns-of-a-grid
// 2025/08/14

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size());
        for (int i = 0; i < grid[0].size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                int width = grid[j][i] <= 0;
                for (; grid[j][i] != 0; grid[j][i] /= 10) {
                    ++width;  
                }

                res[i] = max(res[i], width);
            }
        }

        return res;
    }
};