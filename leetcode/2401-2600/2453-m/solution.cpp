// https://leetcode.com/problems/destroy-sequential-targets
// 2025/08/29

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> freq;
        for (const int n : nums) {
            ++freq[n % space];
        }

        int max_f = 0, min_e = INT_MAX;
        for (const int n : nums) {
            const int f = freq[n % space];
            if (f > max_f) {
                max_f = f;
                min_e = n;
            } else if (f == max_f) {
                min_e = min(min_e, n);
            }
        }

        return min_e;
    }
};