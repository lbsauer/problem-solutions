// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference
// 2025/05/26

class Solution {
public:
    int differenceOfSums(int n, int m) {
        return n * (n + 1) / 2 - (n / m + 1) * (n - n % m);
    }
};