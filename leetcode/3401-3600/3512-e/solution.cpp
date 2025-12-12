// https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k
// 2025/11/28

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(nums.begin(), nums.end(), 0) % k;
    }
};