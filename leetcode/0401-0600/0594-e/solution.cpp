// https://leetcode.com/problems/longest-harmonious-subsequence
// 2025/06/29

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (const int n : nums) {
            ++freq[n];
        }

        int longest = 0;
        for (const auto [n, f] : freq) {
            if (const auto it = freq.find(n + 1); it != freq.end()) {
                longest = max(longest, f + it->second);
            }
        }

        return longest;
    }
};