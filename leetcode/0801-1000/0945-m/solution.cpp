// https://leetcode.com/problems/minimum-increment-to-make-array-unique
// 2024/06/14

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) continue;

            count += nums[i - 1] - nums[i] + 1;
            nums[i] = nums[i - 1] + 1;
        }

        return count;
    }
};