// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k
// 2024/11/19

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        int unique = 0;
        
        unordered_map<int, int> count;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
            unique += ++count[nums[i]] == 1;
        }

        long long max_sum = unique == k ? sum : 0;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];

            unique += ++count[nums[i]] == 1;
            unique -= --count[nums[i - k]] == 0;

            max_sum = max(max_sum, unique == k ? sum : 0);
        }

        return max_sum;
    }
};