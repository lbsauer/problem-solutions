// https://leetcode.com/problems/sum-of-square-numbers
// 2025/10/15

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int l = 0, r = sqrt(c); l <= r;) {
            const int x = c - r * r;
            if (x == l * l) return true;

            l += x > l * l;
            r -= x < l * l;
        }

        return false;
    }
};