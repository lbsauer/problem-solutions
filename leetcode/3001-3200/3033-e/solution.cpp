// https://leetcode.com/problems/modify-the-matrix
// 2024/05/03

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix[0].size(); ++i) {
            int max = -1;
            for (int j = 0; j < matrix.size(); ++j) {
                max = std::max(max, matrix[j][i]);
            }
            for (int j = 0; j < matrix.size(); ++j) {
                if (matrix[j][i] == -1) matrix[j][i] = max;
            }
        }

        return matrix;
    }
};