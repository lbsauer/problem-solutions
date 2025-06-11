// https://leetcode.com/problems/the-kth-factor-of-n
// 2025/06/05

class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        for (; i * i <= n; ++i) {
            if (n % i == 0 && --k == 0) return i;
        }

        --i;
        for (i -= i * i == n; i >= 1; --i) {
            if (n % i == 0 && --k == 0) return n / i;
        }

        return -1;
    }
};