// https://leetcode.com/problems/score-after-flipping-matrix
// 2024/05/13

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int score = grid.size();

        for (int i = 0; i < grid.size(); ++i) {
            if (grid[i][0] == 1) continue;

            for (int j = 0; j < grid[0].size(); ++j) {
                grid[i][j] = grid[i][j] == 1 ? 0 : 1;
            }
        }

        for (int i = 1; i < grid[0].size(); ++i) {
            int count = 0;
            for (int j = 0; j < grid.size(); ++j) {
                count += grid[j][i];
            }
            
            score <<= 1;
            score += std::max(count, (int) (grid.size() - count));
        }

        return score;
    }
};