// https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i
// 2025/08/15

class Solution {
    struct min_op { int operator()(const int lhs, const int rhs) { return min(lhs, rhs); }};

public:
    int minimumSum(vector<int>& nums) {
        vector<int> left(nums.size());
        partial_sum(nums.begin(), nums.end(), left.begin(), min_op{});

        vector<int> right(nums.size());
        partial_sum(nums.rbegin(), nums.rend(), right.rbegin(), min_op{});

        int min_sum = INT_MAX;
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (left[i - 1] <nums[i] && right[i + 1] < nums[i]) {
                min_sum = min(min_sum, left[i - 1] + nums[i] + right[i + 1]);
            }
        }

        return min_sum == INT_MAX ? -1 : min_sum;
    }
};