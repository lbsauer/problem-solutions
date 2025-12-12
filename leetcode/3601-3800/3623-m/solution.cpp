// https://leetcode.com/problems/count-number-of-trapezoids-i
// 2025/12/02

class Solution {
    constexpr static int MOD = 1'000'000'007;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> freq;
        for (const auto& p : points) {
            ++freq[p[1]];
        }

        int count = 0, pairs = 0;
        for (const auto [y, f] : freq) {
            const long long p = (f * (f - 1ll) / 2) % MOD;
            count = (count + p * pairs) % MOD;
            pairs = (pairs + p) % MOD;
        }

        return count;
    }
};