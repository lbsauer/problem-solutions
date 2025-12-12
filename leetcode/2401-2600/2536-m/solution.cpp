// https://leetcode.com/problems/increment-submatrices-by-one
// 2025/11/14

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n));
        for (const auto& q : queries) {
            ++mat[q[0]][q[1]];

            if (q[2] + 1 < n) --mat[q[2] + 1][q[1]];
            if (q[3] + 1 < n) --mat[q[0]][q[3] + 1];

            if (q[2] + 1 < n && q[3] + 1 < n) {
                ++mat[q[2] + 1][q[3] + 1];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                mat[i][j] += mat[i][j - 1];
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < n; ++i) {
                mat[i][j] += mat[i - 1][j];
            }
        }

        return mat;
    }
};