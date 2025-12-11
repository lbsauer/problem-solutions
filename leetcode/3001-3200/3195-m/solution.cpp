// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i
// 2025/08/22

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int left = grid[0].size(), right = -1;
        int top = grid.size(), bottom = -1;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    bottom = max(bottom, i);
                }
            }
        }

        return (right - left + 1) * (bottom - top + 1);
    }
};