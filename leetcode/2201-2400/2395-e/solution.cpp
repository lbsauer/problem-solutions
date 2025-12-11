// https://leetcode.com/problems/find-subarrays-with-equal-sum
// 2025/10/15

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> sums;
        for (int i = 1; i < nums.size(); ++i) {
            if (!sums.insert(nums[i] + nums[i - 1]).second) return true;
        }

        return false;
    }
};