// https://leetcode.com/problems/number-of-substrings-with-only-1s
// 2025/11/16

class Solution {
public:
    int numSub(string s) {
        int count = 0;
        for (int l = 0, r = 0; r < s.size(); l = ++r) {
            while (r < s.size() && s[r] == '1') {
                count = (count + ++r - l) % 1'000'000'007;
            }
        }

        return count;
    }
};