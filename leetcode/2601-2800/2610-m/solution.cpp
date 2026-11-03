// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions
// 2026/08/04

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;

        vector<vector<int>> res;
        for (const int n : nums) {
            const int f = ++freq[n];
            if (res.size() < f) res.emplace_back();
            res[f - 1].push_back(n);
        }

        return res;
    }
};