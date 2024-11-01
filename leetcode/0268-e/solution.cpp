// https://leetcode.com/problems/missing-number
// 2024/07/25

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return -accumulate(nums.begin(), nums.end(), -((nums.size() * (nums.size() + 1)) / 2));
    }
};