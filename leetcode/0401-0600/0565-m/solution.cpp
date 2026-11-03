// https://leetcode.com/problems/array-nesting
// 2026/08/16

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int max_length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int k = nums[i], length = 0; k >= 0; ++length) {
                nums[k] = -(nums[k] + 1);
                k = -nums[k] - 1;
                max_length = max(length, max_length);
            }
        }

        return max_length;
    }
};