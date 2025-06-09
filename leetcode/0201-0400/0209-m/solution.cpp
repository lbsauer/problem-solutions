// https://leetcode.com/problems/minimum-size-subarray-sum
// 2024/11/17

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;

        int sum = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            sum += nums[r];

            while (sum >= target) {
                res = min(res, r - l + 1);
                sum -= nums[l++];
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};