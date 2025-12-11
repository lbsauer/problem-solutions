// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
// 2025/09/12

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        if (n < 10) return {n / 2, (n + 1) / 2};

        int res = 0, p = 1, carry = 0;
        for (int x = n; x >= 10; x /= 10, p *= 10) {
            int target = (x % 10) - carry;
            if (target < 2) target += 10;

            res += target / 2 * p;
            carry = (target + carry) >= 10;
        }

        return {res, n - res};
    }
};