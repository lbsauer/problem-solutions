// https://leetcode.com/problems/path-existence-queries-in-a-graph-i
// 2025/10/15

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n);
        for (int i = 1, curr = 0; i < n; ++i) {
            curr += (nums[i] - nums[i - 1] > maxDiff);
            group[i] = curr;
        }

        vector<bool> res(queries.size());
        for (int i = 0; const auto& q : queries) {
            res[i++] = group[q[0]] == group[q[1]];
        }

        return res;
    }
};