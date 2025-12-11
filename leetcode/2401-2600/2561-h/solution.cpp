// https://leetcode.com/problems/rearranging-fruits
// 2025/08/02

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int min_e = INT_MAX;
        
        unordered_map<int, int> count;
        for (const int n : basket1) {
            ++count[n];
            min_e = min(min_e, n);
        }

        for (const int n : basket2) {
            --count[n];
            min_e = min(min_e, n);
        }

        vector<int> merged;
        for (const auto [n, c] : count) {
            if (c % 2 != 0) return -1;

            for (int i = 0; i < abs(c); i += 2) {
                merged.push_back(n);
            }
        }

        nth_element(merged.begin(), next(merged.begin(), merged.size() / 2), merged.end());

        long long cost = 0;
        for (int i = 0; i < merged.size() / 2; ++i) {
            cost += min(merged[i], min_e * 2);
        }

        return cost;
    }
};