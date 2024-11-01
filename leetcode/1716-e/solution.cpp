// https://leetcode.com/problems/calculate-money-in-leetcode-bank
// 2024/05/03

class Solution {
public:
    int totalMoney(int n) {
        int div = n / 7;
        int mod = n % 7;
        return 28 * div + ((div * div - div) / 2) * 7 + (mod * mod + mod) / 2 + mod * div;
    }
};