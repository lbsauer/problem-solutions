// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array
// 2024-09-18

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        const int total = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0, l = 0; i < nums.size(); ++i) {
            int temp = nums[i];
            nums[i] = (2 * i - nums.size()) * temp - 2 * l + total;
            l += temp;
        }

        return nums;
    }
};