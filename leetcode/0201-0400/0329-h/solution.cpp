// https://leetcode.com/problems/longest-increasing-path-in-a-matrix
// 2024/08/22

class Solution {
public:
    int dfs(const vector<vector<int>>& matrix, vector<vector<int>>& dp, const int i, const int j, const int m, const int n) {
        if (dp[i][j] != 0) return dp[i][j];

        int longest = 0;
        if (i > 0 && matrix[i][j] < matrix[i - 1][j]) {
            longest = max(longest, dfs(matrix, dp, i - 1, j, m, n));
        }
        if (i < m - 1 && matrix[i][j] < matrix[i + 1][j]) {
            longest = max(longest, dfs(matrix, dp, i + 1, j, m, n));
        }
        if (j > 0 && matrix[i][j] < matrix[i][j - 1]) {
            longest = max(longest, dfs(matrix, dp, i, j - 1, m, n));
        }
        if (j < n - 1 && matrix[i][j] < matrix[i][j + 1]) {
            longest = max(longest, dfs(matrix, dp, i, j + 1, m, n));
        }

        dp[i][j] = longest + 1;

        return longest + 1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        int longest = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                longest = max(longest, dfs(matrix, dp, i, j, m, n));
            }
        }

        return longest;
    }
};