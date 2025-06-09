// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i
// 2025/03/18

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        
        for (int i = nums.size() - 1; i >= 2; --i) {
            count += nums[i] ^= 1;
            nums[i - 1] ^= nums[i];
            nums[i - 2] ^= nums[i];
        }

        return nums[0] + nums[1] != 2 ? -1 : count;
    }
};