// https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product
// 2026/08/22

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        for (int x = n; x > 0; x /= 10) {
            sum += x % 10;
            product *= x % 10;
        }

        return n % (sum + product) == 0;
    }
};