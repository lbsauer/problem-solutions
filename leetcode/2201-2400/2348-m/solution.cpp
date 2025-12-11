// https://leetcode.com/problems/number-of-zero-filled-subarrays
// 2025/08/19

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) {
                count += r - l + 1;
            } else {
                l = r + 1;
            }
        }

        return count;
    }
};