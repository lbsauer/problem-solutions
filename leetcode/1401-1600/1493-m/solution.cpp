// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element
// 2025/08/23

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longest = 0;

        int curr = 0, prev = 0;
        for (const int n : nums) {
            if (n == 1) {
                ++curr;
            } else {
                prev = curr;
                curr = 0;
            }

            longest = max(longest, curr + prev);
        }

        return longest - (longest == nums.size());
    }
};