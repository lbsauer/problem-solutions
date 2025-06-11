// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times
// 2024/03/29

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int max_e = *max_element(nums.begin(), nums.end());

        long long count = 0;
        for (int l = 0, r = 0, max_count = 0; r < nums.size(); ++r) {
            max_count += nums[r] == max_e;

            while (max_count == k) {
                max_count -= nums[l++] == max_e;
                count += nums.size() - r;
            }
        }

        return count;
    }
};