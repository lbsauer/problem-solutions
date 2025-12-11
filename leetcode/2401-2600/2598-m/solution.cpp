// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations
// 2025/10/15

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value);
        for (const int n : nums) {
            ++freq[((n % value) + value) % value];
        }

        const auto it = min_element(freq.begin(), freq.end());

        return *it * value + distance(freq.begin(), it);
    }
};