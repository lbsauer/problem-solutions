// https://leetcode.com/problems/house-robber-ii
// 2026/08/16

class Solution {
    int solve(const vector<int>& nums, bool b) {
        int back1 = 0, back2 = 0;
        for (int i = b; i < nums.size() - !b; ++i) {
            back2 = max(back2 + nums[i], back1);
            swap(back1, back2);
        }

        return max(back1, nums[0]);
    }

public:
    int rob(vector<int>& nums) {
        return max(solve(nums, false), solve(nums, true));
    }
};