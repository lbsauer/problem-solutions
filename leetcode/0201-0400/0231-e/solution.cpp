// https://leetcode.com/problems/power-of-two
// 2025/08/08

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};