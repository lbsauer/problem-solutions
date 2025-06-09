// https://leetcode.com/problems/find-all-groups-of-farmland
// 2024/04/21

class Solution {
public:
    void fill(std::vector<std::vector<int>>& matrix, int x, int y, int& max_x, int& max_y) {
        if (y >= matrix.size() || x >= matrix[0].size() || matrix[y][x] != 1) {
            max_x = std::max(max_x, x - 1);
            max_y = std::max(max_y, y - 1);
            return;
        }

        matrix[y][x] = 0;
        fill(matrix, x + 1, y, max_x, max_y);
        fill(matrix, x, y + 1, max_x, max_y);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        std::vector<std::vector<int>> res;
        
        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[0].size(); ++j) {
                if (land[i][j] != 1) continue;

                int max_x = j;
                int max_y = i;
                fill(land, j, i, max_x, max_y);
                res.push_back({i, j, max_y, max_x});
            }
        }

        return res;
    }
};