// https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target
// 2025/07/16

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 0;

        for (const int n : nums) {
            for (int i = target; i >= n; --i) {
                if (dp[i - n] >= 0) dp[i] = max(dp[i], dp[i - n] + 1);
            }
        }

        return dp.back();
    }
};