// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum
// 2026/08/16

class Solution {
    int count(const vector<int>& nums, int limit) {
        int total = 0, curr = 0;
        for (const int n : nums) {
            curr = n <= limit ? curr + 1 : 0;
            total += curr;
        }

        return total;
    }

public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);    
    }
};