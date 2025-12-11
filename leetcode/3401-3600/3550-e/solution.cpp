// https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index
// 2025/08/04

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            while (nums[i] > 0) {
                sum += nums[i] % 10;
                nums[i] /= 10;
            }

            if (sum == i) return i;
        }

        return -1;
    }
};