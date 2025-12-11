// https://leetcode.com/problems/maximum-erasure-value
// 2025/07/24

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> have(*max_element(nums.begin(), nums.end()) + 1);

        int max_score = 0;
        for (int l = 0, r = 0, sum = 0; r < nums.size(); ++r) {
            while (have[nums[r]]) {
                sum -= nums[l];
                have[nums[l++]] = false;
            }

            sum += nums[r];
            have[nums[r]] = true;

            max_score = max(max_score, sum);
        }

        return max_score;
    }
};