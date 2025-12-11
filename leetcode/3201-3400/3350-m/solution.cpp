// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii
// 2025/09/26

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int k = 1;
        for (int l = 0, r = 1, prev = 0; r < nums.size(); l = r++) {
            while (r < nums.size() && nums[r] > nums[r - 1]) ++r;

            k = max({k, min(r - l, prev), (r - l) / 2});
            prev = r - l;
        }

        return k;
    }
};