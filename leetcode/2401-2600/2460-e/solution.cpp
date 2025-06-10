// https://leetcode.com/problems/apply-operations-to-an-array
// 2025/03/07

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) continue;

            nums[i - 1] *= 2;
            nums[i++] = 0;
        }

        using namespace placeholders;
        stable_partition(nums.begin(), nums.end(), bind(greater<int>{}, _1, 0));

        return nums;
    }
};