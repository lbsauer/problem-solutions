// https://leetcode.com/problems/minimum-falling-path-sum
// 2025/06/14

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int smallest = matrix[i - 1][j];
                if (j > 0)     smallest = min(smallest, matrix[i - 1][j - 1]);
                if (j < n - 1) smallest = min(smallest, matrix[i - 1][j + 1]);

                matrix[i][j] += smallest;
            }
        }

        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};