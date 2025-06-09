// https://leetcode.com/problems/spiral-matrix-ii
// 2024/05/11

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int l = 0;
        int r = n - 1;
        int t = 0;
        int b = n - 1;

        int max = n * n;
        int j = 0;

        while (j != max) {
            for (int i = l; i <= r && j != max; ++i) {
                matrix[t][i] = ++j;
            }
            ++t;

            for (int i = t; i <= b && j != max; ++i) {
                matrix[i][r] = ++j;
            }
            --r;

            for (int i = r; i >= l && j != max; --i) {
                matrix[b][i] = ++j;
            }
            --b;

            for (int i = b; i >= t && j != max; --i) {
                matrix[i][l] = ++j;
            }
            ++l;
        }

        return matrix;
    }
};