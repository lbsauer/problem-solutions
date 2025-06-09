// https://leetcode.com/problems/minimum-array-end
// 2024/09/11

class Solution {
public:
    long long minEnd(int n, int x) {
        --n;

        long long res = x;
        for (int i = 0; n > 0; ++i, x >>= 1) {
            if (x & 1) continue;

            res |= (n & 1ll) << i;
            n >>= 1;
        }

        return res;
    }
};