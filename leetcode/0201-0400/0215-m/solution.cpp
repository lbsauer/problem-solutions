// https://leetcode.com/problems/kth-largest-element-in-an-array
// 2025/11/22

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), next(nums.begin(), k - 1), nums.end(), greater<int>{});
        return nums[k - 1];
    }
};