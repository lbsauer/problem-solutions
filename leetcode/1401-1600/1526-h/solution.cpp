// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array
// 2025/10/15

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prev = 0, ops = 0;
        for (const int t : target) {
            ops += max(t - prev, 0);
            prev = t;
        }

        return ops;
    }
};