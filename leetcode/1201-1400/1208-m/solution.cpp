// https://leetcode.com/problems/get-equal-substrings-within-budget
// 2025/08/23

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        for (int i = 0; i < s.size(); ++i) {
            s[i] = abs(s[i] - t[i]);
        }
        
        int max_length = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            for (maxCost -= s[r]; maxCost < 0; ++l) {
                maxCost += s[l];
            }

            max_length = max(max_length, r - l + 1);
        }

        return max_length;
    }
};