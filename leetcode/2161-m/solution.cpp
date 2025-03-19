// https://leetcode.com/problems/partition-array-according-to-given-pivot
// 2025/03/05

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        using namespace placeholders;

        const auto it = stable_partition(nums.begin(), nums.end(), bind(less_equal<int>{}, _1, pivot));
        stable_partition(nums.begin(), it, bind(less<int>{}, _1, pivot));

        return nums;
    }
};