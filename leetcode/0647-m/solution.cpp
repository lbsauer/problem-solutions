// https://leetcode.com/problems/palindromic-substrings
// 2024/08/15

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (float i = 0; i <= s.length() - 1; i += 0.5) {
            for (int l = floor(i), r = ceil(i); l >= 0 && r < s.length(); --l, ++r) {
                if (s[l] != s[r]) break;

                ++count;
            }
        }

        return count;
    }
};