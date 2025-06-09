// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and
// 2024/05/09

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_value = *std::max_element(nums.begin(), nums.end());
        int max_length = 1;

        for (int i = 0, len = 0; i < nums.size(); ++i) {
            if (nums[i] == max_value) {
                ++len;
            } else {
                len = 0;
            }
            
            max_length = std::max(max_length, len);
        }

        return max_length;
    }
};