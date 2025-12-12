// https://leetcode.com/problems/ones-and-zeroes
// 2025/11/11

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (const string& s : strs) {
            const int z = count(s.begin(), s.end(), '0');
            const int o = s.size() - z;

            for (int i = m; i >= z; --i) {
                for (int j = n; j >= o; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - z][j - o]);
                }
            }
        }

        return dp[m][n];
    }
};