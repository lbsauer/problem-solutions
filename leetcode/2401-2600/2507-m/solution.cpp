// https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors
// 2025/10/16

class Solution {
public:
    int smallestValue(int n) {
        int sum = 0, x = n;
        for (int i = 2; i * i <= n && x > 1; ++i) {
            while (x % i == 0) {
                sum += i;
                x /= i;
            }
        }

        sum += x - (x == 1);

        return sum == n ? n : smallestValue(sum);
    }
};