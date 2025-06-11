// https://leetcode.com/problems/count-subarrays-with-score-less-than-k
// 2025/04/27

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;
        
        for (long long l = 0, r = 0, sum = 0; r < nums.size(); ++r) {
            sum += nums[r];

            while (sum * (r - l + 1) >= k) {
                sum -= nums[l++];
            }

            count += r - l + 1;
        }

        return count;
    }
};