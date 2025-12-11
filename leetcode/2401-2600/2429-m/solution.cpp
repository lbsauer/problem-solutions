// https://leetcode.com/problems/minimize-xor
// 2025/08/26

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2);

        int x = 0;
        for (int i = 31; i >= 0 && count > 0; --i) {
            const int b = (num1 >> i) & 1;
            x ^= b << i;
            count -= b;
        }

        for (int i = 0; i < 32 && count > 0; ++i) {
            const int b = (x >> i) & 1 ^ 1;
            x ^= b << i;
            count -= b;
        }

        return x;
    }
};