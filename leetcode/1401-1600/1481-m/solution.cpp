// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals
// 2025/03/10

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (const int n : arr) {
            ++freq[n];
        }

        vector<int> freq_count(arr.size() + 1);
        for (const auto& p : freq) {
            ++freq_count[p.second];
        }

        int res = freq.size();
        for (int i = 1; i < freq_count.size(); ++i) {
            if (freq_count[i] * i >= k) return res - k / i;

            k -= freq_count[i] * i;
            res -= freq_count[i];
        }

        return res;
    }
};