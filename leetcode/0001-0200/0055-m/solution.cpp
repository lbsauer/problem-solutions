// https://leetcode.com/problems/jump-game
// 2024/07/22

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (max_idx < i) break;

            max_idx = max(max_idx, i + nums[i]);
        }

        return max_idx >= (nums.size() - 1);
    }
};