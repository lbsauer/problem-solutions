// https://leetcode.com/problems/longest-palindromic-subsequence
// 2024/08/15

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length()));

        for (int i = s.length() - 1; i >= 0; --i) {
            dp[i][i] = 1;

            for (int j = i + 1; j < s.length(); ++j) {
                dp[i][j] = (s[i] == s[j])
                    ? dp[i + 1][j - 1] + 2
                    : max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][s.length() - 1];
    }
};