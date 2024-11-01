// https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-ii
// 2024/08/18

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int left = 0;
        for (; left < nums.size() - 1; ++left) {
            if (nums[left] >= nums[left + 1]) break;
        }

        if (left == nums.size() - 1) {
            return nums.size() * (nums.size() + 1) / 2;
        }

        int right = nums.size() - 1;
        for (; right > 0; --right) {
            if (nums[right] <= nums[right - 1]) break;
        }

        long long total = left + 2 + nums.size() - right;
        for (int i = 0, j = right; i <= left && j < nums.size(); ++i) {
            while (j < nums.size() && nums[j] <= nums[i]) ++j;

            total += nums.size() - j;
        }

        return total;
    }
};