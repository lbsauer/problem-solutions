// https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers
// 2025/08/12

class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> dp(n + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            const int p = pow(i, x);
            if (p > n) break;

            for (int j = n; j >= p; --j) {
                dp[j] = (dp[j] + dp[j - p]) % 1'000'000'007;
            }
        }

        return dp[n];
    }
};