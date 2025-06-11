// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i
// 2025/06/10

class Solution {
public:
    int maxDifference(string s) {
        int freq[26]{};
        for (const char c : s) {
            ++freq[c - 'a'];
        }

        int max_odd = 0, min_even = INT_MAX;
        for (const int f : freq) {
            if (f & 1) {
                max_odd = max(max_odd, f);
            } else {
                min_even = f == 0 ? min_even : min(min_even, f);
            }
        }

        return max_odd - min_even;
    }
};