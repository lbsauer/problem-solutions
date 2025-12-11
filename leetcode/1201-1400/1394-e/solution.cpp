// https://leetcode.com/problems/find-lucky-integer-in-an-array
// 2025/07/04

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (const int n : arr) {
            ++freq[n];
        }

        int largest = -1;
        for (const auto [n, f] : freq) {
            if (n == f) largest = max(largest, n);
        }

        return largest;
    }
};