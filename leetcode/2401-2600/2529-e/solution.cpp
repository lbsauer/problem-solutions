// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer
// 2025/03/11

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        const auto [first, last] = equal_range(nums.begin(), nums.end(), 0);
        return max(distance(nums.begin(), first), distance(last, nums.end()));
    }
};