// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k
// 2024/04/30

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int num = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            num ^= nums[i];
        }

        int count = 0;
        while (num | k) {
            count += (num & 1) ^ (k & 1);
            num = num >> 1;
            k = k >> 1;
        }

        return count;
    }
};