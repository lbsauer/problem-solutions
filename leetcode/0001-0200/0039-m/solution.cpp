// https://leetcode.com/problems/combination-sum
// 2025/05/14

class Solution {
    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& curr, int target, int start) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] > target) break;

            curr.push_back(nums[i]);
            backtrack(res, nums, curr, target - nums[i], i);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        curr.reserve(target / candidates.front());

        vector<vector<int>> res;
        backtrack(res, candidates, curr, target, 0);

        return res;
    }
};