// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k
// 2025/08/29

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k);
        for (const int i : arr) {
            ++freq[((i % k) + k) % k];
        }

        if (freq[0] % 2 == 1) return false;

        for (int i = 1; i <= k / 2; ++i) {
            if (freq[i] != freq[k - i]) return false;
        }

        return true;
    }
};