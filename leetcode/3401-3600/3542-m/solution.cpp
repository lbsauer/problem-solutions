// https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero
// 2025/11/09

class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s{0};
        
        int count = 0;
        for (const int n : nums) {
            while (!s.empty() && n < s.back()) {
                s.pop_back();
            }

            if (s.empty() || s.back() < n) {
                ++count;
                s.push_back(n);
            }
        }

        return count;
    }
};