// https://leetcode.com/problems/sum-of-squares-of-special-elements
// 2025/10/15

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0, i = 1, n = nums.size();
        for (; i * i < n; ++i) {
            if (n % i != 0) continue;
            
            sum += nums[i - 1] * nums[i - 1];
            sum += nums[n / i - 1] * nums[n / i - 1];
        }

        if (i * i == n) sum += nums[i - 1] * nums[i - 1];

        return sum;
    }
};