// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away
// 2025/11/17

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -k - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1 && i - last <= k) return false;
            last = nums[i] == 1 ? i : last;
        }

        return true;
    }
};