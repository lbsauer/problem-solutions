// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements
// 2025/07/17

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        const int n = nums.size() / 3;

        long long sum_left = accumulate(nums.begin(), next(nums.begin(), n), 0ll);
        priority_queue<int> left(nums.begin(), next(nums.begin(), n));

        vector<long long> min_sum(n + 1);
        min_sum[0] = sum_left;

        for (int i = n; i < 2 * n; ++i) {
            left.push(nums[i]);
            sum_left += nums[i] - left.top();
            left.pop();

            min_sum[i - n + 1] = sum_left;
        }

        long long sum_right = accumulate(nums.rbegin(), next(nums.rbegin(), n), 0ll);
        priority_queue<int, vector<int>, greater<int>> right(nums.rbegin(), next(nums.rbegin(), n));

        long long min_diff = min_sum.back() - sum_right;
        for (int i = n * 2 - 1; i >= n; --i) {
            right.push(nums[i]);
            sum_right += nums[i] - right.top();
            right.pop();

            min_diff = min(min_diff, min_sum[i - n] - sum_right);
        }

        return min_diff;
    }
};