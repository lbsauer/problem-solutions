// https://leetcode.com/problems/combination-sum-iii
// 2025/10/16

class Solution {
    void backtrack(vector<vector<int>>& res, vector<int>& curr, int k, int n, int idx) {
        if (k == 0) {
            if (n == 0) res.push_back(curr);
            return;
        }
        
        for (int i = idx; i <= 9 && n - i >= 0; ++i) {
            curr.push_back(i);
            backtrack(res, curr, k - 1, n - i, i + 1);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;

        backtrack(res, curr, k, n, 1);

        return res;
    }
};