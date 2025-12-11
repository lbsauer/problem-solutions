// https://leetcode.com/problems/four-divisors
// 2025/07/31

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total_sum = 0;
        for (const int n : nums) {
            int count = 0, sum = 0, last = 0;
            for (int i = 1; i * i <= n && count <= 4; last = i++) {
                if (n / i * i == n) {
                    sum += i + (n / i);
                    count += 2;
                }
            }

            if (count == 4 && last * last != n) total_sum += sum;
        }

        return total_sum;
    }
};