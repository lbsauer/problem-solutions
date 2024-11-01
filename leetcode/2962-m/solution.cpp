// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times
// 2024/03/29

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max = *max_element(nums.begin(), nums.end());

        long long count = 0;
        int count_max = 0;

        for (int r = 0, l = 0; r < nums.size(); ++r) {
            if (nums[r] != max) continue;

            ++count_max;
            if (count_max == k) {
                count += (nums.size() - r);
                
                while (count_max == k) {
                    if (nums[l] == max) {
                        --count_max;
                    } else {
                        count += (nums.size() - r);
                    }
                    ++l;
                }
            }
        }

        return count;
    }
};