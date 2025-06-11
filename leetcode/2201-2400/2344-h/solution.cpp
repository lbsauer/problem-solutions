// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible
// 2025/06/09

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int div = numsDivide[0];
        for (int i = 1; i < numsDivide.size() && div > 1; ++i) {
            div = gcd(div, numsDivide[i]);
        }

        int smallest = INT_MAX;
        for (const int n : nums) {
            if (div / n * n == div) smallest = min(smallest, n);
        }

        if (smallest == INT_MAX) return -1;

        return count_if(nums.begin(), nums.end(), [smallest](const int n) { return n < smallest; });
    }
};