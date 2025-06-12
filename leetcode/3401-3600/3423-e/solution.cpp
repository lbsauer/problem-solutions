// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array
// 2025/06/11

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int max_diff = abs(nums.front() - nums.back());
        for (int i = 1; i < nums.size(); ++i) {
            max_diff = max(max_diff, abs(nums[i] - nums[i - 1]));
        }

        return max_diff;
    }
};