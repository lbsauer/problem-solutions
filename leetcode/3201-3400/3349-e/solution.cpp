// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i
// 2025/10/14

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        bool last = false;
        for (int l = 0, r = 1; l < nums.size(); l = r++) {
            while (r < nums.size() && nums[r] > nums[r - 1]) ++r;

            if (r - l >= k * 2 || r - l >= k && last) return true;

            last = r - l >= k;
        }

        return false;
    }
};