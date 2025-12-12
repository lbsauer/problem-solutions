// https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned
// 2025/10/16

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int count = 0, max_e = 0;
        for (int i = 0; i < flips.size(); ++i) {
            max_e = max(max_e, flips[i]);
            count += max_e == i + 1;
        }

        return count;
    }
};