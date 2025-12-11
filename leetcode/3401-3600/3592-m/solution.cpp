// https://leetcode.com/problems/inverse-coin-change
// 2025/09/26

class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> dp(numWays.size() + 1);
        dp[0] = 1;

        vector<int> res;
        for (int i = 1; i < dp.size(); ++i) {
            if (dp[i] == numWays[i - 1]) continue;

            if (numWays[i - 1] - dp[i] != 1) return {};

            res.push_back(i);
            for (int j = i; j < dp.size(); ++j) {
                dp[j] += dp[j - i];
            }
        }

        return res;
    }
};