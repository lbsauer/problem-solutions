// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i
// 2026/01/31

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) {
            second = max(first, min(second, nums[i]));
            first = min(first, nums[i]);
        }

        return nums[0] + first + second;
    }
};