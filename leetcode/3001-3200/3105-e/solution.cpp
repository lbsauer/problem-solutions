// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray
// 2025/02/03

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_length = 1;

        for (int i = 1, inc = 1, dec = 1; i < nums.size(); ++i) {
            inc = nums[i] > nums[i - 1] ? inc + 1 : 1;
            dec = nums[i] < nums[i - 1] ? dec + 1 : 1;

            max_length = max({max_length, inc, dec});
        }

        return max_length;
    }
};