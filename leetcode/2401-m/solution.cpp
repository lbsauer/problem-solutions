// https://leetcode.com/problems/longest-nice-subarray
// 2025/03/18

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int longest{};

        for (int l{}, r{}, mask{}; r < nums.size(); ++r) {
            while ((mask & nums[r]) != 0) {
                mask ^= nums[l++];
            }

            mask |= nums[r];
            longest = max(longest, r - l + 1);
        }

        return longest;
    }
};