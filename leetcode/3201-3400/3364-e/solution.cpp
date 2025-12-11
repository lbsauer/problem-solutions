// https://leetcode.com/problems/minimum-positive-sum-subarray
// 2025/08/03

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        partial_sum(nums.begin(), nums.end(), nums.begin());

        multiset<int> set;

        int min_sum = INT_MAX;
        for (int i = l - 1, prev = 0; i < nums.size() + r - l; ++i) {
            if (i < nums.size()) set.insert(nums[i]);
            
            if (i >= r) {
                prev = nums[i - r];
                set.erase(set.find(nums[i - (r - l + 1)]));
            }

            const auto it = set.upper_bound(prev);
            if (it != set.end()) min_sum = min(min_sum, *it - prev);
        }

        return min_sum == INT_MAX ? -1 : min_sum;
    }
};