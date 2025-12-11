// https://leetcode.com/problems/non-decreasing-subsequences
// 2025/08/26

class Solution {
    void backtrack(const vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int idx, int last) {
        if (idx == nums.size()) {
            if (curr.size() > 1) res.push_back(curr);
            return;
        }

        if (nums[idx] >= last) {
            curr.push_back(nums[idx]);
            backtrack(nums, res, curr, idx + 1, nums[idx]);
            curr.pop_back();
        }

        if (nums[idx] != last) backtrack(nums, res, curr, idx + 1, last);
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;

        backtrack(nums, res, curr, 0, INT_MIN);

        return res;
    }
};