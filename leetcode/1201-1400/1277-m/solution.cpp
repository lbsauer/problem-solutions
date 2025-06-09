// https://leetcode.com/problems/count-square-submatrices-with-all-ones
// 2024/08/21

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int total = 0;
        for (int i = matrix.size() - 2; i >= 0; --i) {
            for (int j = matrix[0].size() - 2; j >= 0; --j) {
                if (matrix[i][j] == 0) continue;

                matrix[i][j] = 1 + min({matrix[i + 1][j + 1], matrix[i][j + 1], matrix[i + 1][j]});
                total += matrix[i][j];
            }
        }

        for (int i = 0; i < matrix.size() - 1; ++i) {
            total += matrix[i].back();
        }

        for (int i = 0; i < matrix[0].size(); ++i) {
            total += matrix.back()[i];
        }

        return total;
    }
};